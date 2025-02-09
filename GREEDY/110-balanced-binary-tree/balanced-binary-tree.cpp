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
int heightofbst(TreeNode* root, int &diff){
    if(root==nullptr){
        return 0;
    }

    int lh=heightofbst(root->left, diff);
    int rh=heightofbst(root->right, diff);


    if(abs(lh-rh)>1){
        diff= -1;
    }

    return 1+max(lh,rh);


   

    
}


    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int diff=0;

        heightofbst( root, diff);

        if(diff==-1){
            return false;
        }

        return true;



  
      
    


        


      

      






        
    }
 
   
};