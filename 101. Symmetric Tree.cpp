#include <iostream>
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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*>q1, q2;
		vector<int>ans1, ans2;
		q1.push(root);
		q2.push(root);
		while (!q1.empty()) {
			TreeNode* u = q1.front();
			q1.pop();
			if (u == NULL) ans1.push_back(-1);
			else {
				ans1.push_back(u->val);
				q1.push(u->left);
				q1.push(u->right);
			}
		}
		while (!q2.empty()) {
			TreeNode* u = q2.front();
			q2.pop();
			if (u == NULL) ans2.push_back(-1);
			else {
				ans2.push_back(u->val);
				q2.push(u->right);
				q2.push(u->left);
			}
		}
		return ans1 == ans2;
	}
};

int main() {
	Solution s;
	TreeNode* v = new TreeNode(1);
	v->left = new TreeNode(2);
	v->right = new TreeNode(2);
	v->left->left = new TreeNode(3);
	v->left->right = new TreeNode(4);
	v->right->left = new TreeNode(4);
	v->right->right = new TreeNode(3);
	cout << s.isSymmetric(v);
}