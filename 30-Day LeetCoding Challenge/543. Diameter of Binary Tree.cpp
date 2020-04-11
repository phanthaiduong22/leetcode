class Solution {
public:
	int ans = 0;
	int highTree(TreeNode* root) {
		if (root == NULL) return 0;
		return max(highTree(root->left), highTree(root->right)) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) return 0;
		int a = highTree(root->left);
		int b = highTree(root->right);
		if (a + b > ans) ans = a + b;
		if (root->left != NULL) diameterOfBinaryTree(root->left);
		if (root->right != NULL) diameterOfBinaryTree(root->right);
		return ans;
	}
};
