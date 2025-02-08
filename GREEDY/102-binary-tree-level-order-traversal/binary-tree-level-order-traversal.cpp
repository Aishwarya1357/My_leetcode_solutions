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


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        queue<TreeNode*>dq;
         if(!root) return ans;
        dq.push(root);

        while(!dq.empty()){
            vector<int>ds;
            int n=dq.size();
            for(int i=0;i<n;i++){
              TreeNode* node=dq.front();
              dq.pop();
              if(node->left!=nullptr){
                dq.push(node->left);
              }
              if(node->right!=nullptr){
                dq.push(node->right);
              }
               ds.push_back(node->val);

            }
            ans.push_back(ds);


        }
        
             return ans;

    }

        

        
    
};