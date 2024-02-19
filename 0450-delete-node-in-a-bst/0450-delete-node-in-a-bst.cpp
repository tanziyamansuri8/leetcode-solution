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
     TreeNode* minNode(TreeNode* root){
         if(root == NULL)return NULL;
         TreeNode* temp = root;
          while(temp ->left) temp = temp->left;
         return temp;
     }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)return NULL;
        if(root->val == key){
            if(!root->left && ! root ->right ){
                delete root ;
                return NULL;
            }
            else if (root->left && ! root->right){
                TreeNode* childSubtree = root->left;
                delete root;
                return childSubtree;
            }
            else if(!root->left &&  root->right){
                TreeNode * childSubtree = root->right;
                delete root;
                return childSubtree;
            }
            else{
                TreeNode* mini = minNode(root->right);
                root->val = mini->val;
                root->right = deleteNode(root->right,mini->val);
                return root;
                
            }
        }
         else if(root->val > key){
              root->left = deleteNode(root->left ,key);
         }
        
             else {
                 
             
                 root->right = deleteNode(root->right ,key);
         }
        return root;
        
    }
};