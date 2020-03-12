#include <iostream>
#include <algorithm>

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
	int highTree(TreeNode* root) {
		if (root == NULL) return 0;
		return max(highTree(root->left), highTree(root->right)) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int a = highTree(root->left);
		int b = highTree(root->right);
		if (a + b > ans) ans = a + b;
		if (root->left != NULL) diameterOfBinaryTree(root->left);
		if (root->right != NULL) diameterOfBinaryTree(root->right);
		return ans;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	Solution s;
	cout << s.diameterOfBinaryTree(root);
}