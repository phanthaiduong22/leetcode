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
	vector<int>a;
	void inorder(TreeNode* root) {
		if (root == NULL) return;
		inorder(root->left);
		a.push_back(root->val);
		inorder(root->right);
	}
	bool isValidBST(TreeNode* root) {
		if (root == NULL) return true;
		inorder(root);
		for (int i = 1; i < a.size(); i++) {
			if (a[i] <= a[i - 1])
				return false;
		}
		return true;
	}
};

int main() {

}