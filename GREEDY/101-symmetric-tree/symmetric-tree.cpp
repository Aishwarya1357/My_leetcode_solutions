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
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr)  
            return left == right; // Returns true if both are null, false if only one is null

        if (left->val != right->val)  
            return false; // If values don't match, return false

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {  
        if (root == nullptr)  
            return true;  
        return isMirror(root->left, root->right);  
    }
};
