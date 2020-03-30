#include <iostream>
#include <vector>

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
	void recursionGo(TreeNode* root) {
		if (root == NULL) return;
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
			ans += root->left->val;
		if (root->left != NULL)
			recursionGo(root->left);
		if (root->right != NULL)
			recursionGo(root->right);
	}
	int sumOfLeftLeaves(TreeNode* root) {
		recursionGo(root);
		return ans;
	}
};

int main() {
	TreeNode* root = new TreeNode(-9);
	root->left = new TreeNode(-3);
	root->right = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(-6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(0);
	root->right->left->left = new TreeNode(-5);
	Solution s;
	cout << s.sumOfLeftLeaves(root);
}