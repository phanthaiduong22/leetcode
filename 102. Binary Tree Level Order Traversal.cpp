#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>ans;
		queue < pair<TreeNode*, int>>q;
		if (root == NULL)
			return ans;
		else
			q.push(make_pair(root, 0));
		while (!q.empty()) {
			pair<TreeNode*, int> u = q.front();
			q.pop();
			if (ans.size() <= u.second)
			{
				ans.push_back(vector<int>());
				ans[ans.size() - 1].push_back(u.first->val);
			}
			else
				ans[u.second].push_back(u.first->val);
			if (u.first->left != NULL) {
				q.push({ u.first->left,u.second + 1 });
			}
			if (u.first->right != NULL) {
				q.push({ u.first->right,u.second + 1 });
			}
		}
		//for (int i = 0; i < ans.size(); i++) {
		//	for (int j = 0; j < ans[i].size(); j++) {
		//		cout << ans[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		return ans;
	}
};

int main() {
	Solution s;
	TreeNode* v = new TreeNode(3);
	v->left = new TreeNode(9);
	v->right = new TreeNode(20);
	v->right->left = new TreeNode(15);
	v->right->right = new TreeNode(7);
	s.levelOrder(v);
}