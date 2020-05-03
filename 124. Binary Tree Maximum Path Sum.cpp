#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int max_path_sum;
	int maxPathSum(TreeNode* root) {
		max_path_sum = INT_MIN;
		pathSum(root);
		return max_path_sum;
	}
	int pathSum(TreeNode* root) {
		if (root == NULL) return 0;
		int left = max(0, pathSum(root->left));
		int right = max(0, pathSum(root->right));
		max_path_sum = max(max_path_sum, left + right + root->val);
		return max(left, right) + root->val;
	}
};

int main() {

}