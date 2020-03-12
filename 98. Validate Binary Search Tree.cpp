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
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		if (root->left != NULL && root->left->val > root->val) return false;
		if (root->right != NULL && root->right->val < root->val) return false;
		if (!isValidBST(root->left) || !isValidBST(root->right)) return false;
		return true;
	}
};

int main() {
	TreeNode* s = new TreeNode(5);
	s->left = new TreeNode(1);
	s->right = new TreeNode(4);
	s->right->left = new TreeNode(3);
	s->right->right = new TreeNode(6);
	Solution v;
	cout << v.isValidBST(s);
}