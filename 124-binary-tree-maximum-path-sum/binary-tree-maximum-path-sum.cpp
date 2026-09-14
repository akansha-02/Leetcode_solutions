/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    int solve(TreeNode* root, int &maxSum) {

        if (root == NULL) {
            return 0;
        }

        int left = max(0, solve(root->left, maxSum));
        int right = max(0, solve(root->right, maxSum));

        // Path passing through current node
        int currentSum = root->val + left + right;

        // Update global answer
        maxSum = max(maxSum, currentSum);

        // Return only one branch to parent
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};