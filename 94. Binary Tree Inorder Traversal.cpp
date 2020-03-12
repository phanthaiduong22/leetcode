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
	vector<int>ans;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL)
			return ans;
		if (root->left != NULL)
			inorderTraversal(root->left);
		ans.push_back(root->val);
		if (root->right != NULL)
			inorderTraversal(root->right);
		return ans;
	}
};