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
	int ans = 0;
	void DFS(TreeNode* root, int sum, int result) {
		if (sum == result)
			ans++;
		if (root->left != NULL)
			DFS(root->left, sum + root->left->val, result);
		if (root->right != NULL)
			DFS(root->right, sum + root->right->val, result);
	}
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL) return 0;
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* u = q.front();
			q.pop();
			DFS(u, u->val, sum);
			if (u->left != NULL) q.push(u->left);
			if (u->right != NULL) q.push(u->right);
		}
		return ans;
	}
};
int main() {
	TreeNode* v = new TreeNode(10);
	v->left = new TreeNode(5);
	v->right = new TreeNode(-3);
	v->left->left = new TreeNode(3);
	v->left->right = new TreeNode(2);
	v->left->left->left = new TreeNode(3);
	v->left->left->right = new TreeNode(-2);
	v->left->right->right = new TreeNode(1);
	v->right->right = new TreeNode(11);
	Solution s;
	cout << s.pathSum(v, 8);
}