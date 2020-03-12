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
	TreeNode* mergeTrees(TreeNode*& t1, TreeNode*& t2) {
		if (t1 == NULL && t2 != NULL) {
			t1 = new TreeNode(t2->val);
		}
		else if (t1 != NULL && t2 != NULL) {
			t1->val += t2->val;
		}
		if (t1 == NULL || t2 == NULL) return t1;
		if (t1->left != NULL || t2->left != NULL) mergeTrees(t1->left, t2->left);
		if (t1->right != NULL || t2->right != NULL) mergeTrees(t1->right, t2->right);
		return t1;
	}
};

int main() {
	Solution s;
	TreeNode* t1 = new TreeNode(1);
	t1->left = new TreeNode(3);
	t1->right = new TreeNode(2);
	t1->left->left = new TreeNode(5);
	TreeNode* t2 = new TreeNode(2);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(3);
	t2->left->right = new TreeNode(4);
	t2->right->right = new TreeNode(7);
	s.mergeTrees(t1, t2);
}