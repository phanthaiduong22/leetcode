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
	int rob(TreeNode* root) {
		if (root == NULL) return 0;
		if (root->left == root->right && root->left == NULL) return root->val;
		if (root->left == NULL)
	}
};

int main() {
	TreeNode* v = new TreeNode(3);
	v->left = new TreeNode(4);
	v->left->right = new TreeNode(3);
	v->left->left = new TreeNode(1);
	v->right = new TreeNode(5);
	v->right->right = new TreeNode(1);
}