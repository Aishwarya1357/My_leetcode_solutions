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
public:
    int bst(TreeNode* root, int &maxi) {
        if (root == nullptr) {
            return 0;
        }

        // Compute left and right max path sums, ignoring negative contributions
        int lh = max(0, bst(root->left, maxi));
        int rh = max(0, bst(root->right, maxi));

        // Update the maximum path sum (including the current node)
        maxi = max(maxi, root->val + lh + rh);

        // Return max path sum considering at most one child
        return root->val + max(lh, rh);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = root->val;  // Initialize with root->val to ensure at least one node is considered
        bst(root, maxi);
        return maxi;
    }
};
