#include <iostream>

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
	void backtracking(TreeNode* root, int  sum, int result) {
		sum += root->val;
		if (sum == result && root->left == NULL && root->right == NULL) {
			ans = 1;
			return;
		}
		if (ans == 1) return;
		if (root->left != NULL) backtracking(root->left, sum, result);
		if (root->right != NULL) backtracking(root->right, sum, result);
	}
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		backtracking(root, 0, sum);
		return ans;
	}
};

int main() {
}