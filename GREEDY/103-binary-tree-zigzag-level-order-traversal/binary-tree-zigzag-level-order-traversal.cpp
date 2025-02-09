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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>res;
        if(!root){
            return res;
        }
        queue<TreeNode*>q;
        bool lefttoright= true;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int>ds(n);

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int index=(lefttoright)?i:(n-i-1);
                ds[index]=node->val;

                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }

            }

            lefttoright=!lefttoright;
            res.push_back(ds);
        }

        return res;


        
    }
};