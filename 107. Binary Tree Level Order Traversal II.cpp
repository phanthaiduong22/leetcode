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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>ans;
		if (root == NULL) return ans;
		queue<pair<TreeNode*, int>>q;
		q.push(make_pair(root, 0));
		while (!q.empty()) {
			TreeNode* u = q.front().first;
			int v = q.front().second;
			q.pop();
			if (v < ans.size())
				ans[v].push_back(u->val);
			else
				ans.push_back(vector<int>(1, u->val));
			if (u->left != NULL) q.push({ u->left, v + 1 });
			if (u->right != NULL) q.push({ u->right, v + 1 });
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
		return ans;
	}
};
int main() {
	TreeNode* v = new TreeNode(3);
	v->left = new TreeNode(9);
	v->right = new TreeNode(20);
	v->right->left = new TreeNode(15);
	v->right->right = new TreeNode(7);
	Solution s;
	s.levelOrderBottom(v);
}