#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void findUnAncestor(TreeNode* root, int& value, vector<TreeNode*>& a) {
		if (root == NULL || root->val == value) return;
		if (root->left != NULL) findUnAncestor(root->left, value, a);
		if (root->right != NULL) findUnAncestor(root->right, value, a);
		if (root->left != NULL && root->left->val == value) {
			a.push_back(value);
			value = root->val;
		}
		if (root->right != NULL && root->right->val == value) {
			a.push_back(value);
			value = root->val;
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*>a, b;
		findUnAncestor(root, p->val, a);
		findUnAncestor(root, q->val, b);
		a.push_back(root);
		b.push_back(root);
		map<TreeNode*, int>d;
		for (int i = 0; i < a.size(); i++)
			d[a[i]]++;
		for (int i = 0; i < b.size(); i++)
			if (d[b[i]] > 0)
				return a[i];
		return root;
	}
};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	TreeNode *p = root->left->right->right;
	TreeNode* q = root->left->left;

	Solution s;
	s.lowestCommonAncestor(root, p, q);

}