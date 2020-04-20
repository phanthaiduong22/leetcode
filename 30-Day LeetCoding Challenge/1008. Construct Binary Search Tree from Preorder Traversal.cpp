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
	void BST(TreeNode*& root, int x) {
		if (root->val < x) {
			if (root->right == NULL)
				root->right = new TreeNode(x);
			else
				BST(root->right, x);
		}
		else {
			if (root->left == NULL)
				root->left = new TreeNode(x);
			else
				BST(root->left, x);
		}
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if (preorder.size() == 0) return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		for (int i = 1; i < preorder.size(); i++)
			BST(root, preorder[i]);
		return root;
	}
};

int main() {
	vector<int> v = { 1,3 };
	Solution s;
	s.bstFromPreorder(v);
}