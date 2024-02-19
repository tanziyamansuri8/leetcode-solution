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
    bool solve(TreeNode* root, long long lowerBound, long long upperBound) {
        if (root == NULL) return true; // Return true for NULL nodes
        bool cond1 = (root->val > lowerBound && root->val < upperBound);
        bool cond2 = solve(root->left, lowerBound, root->val) && solve(root->right, root->val, upperBound); // Add upperBound argument
        return cond1 && cond2;
    } 
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX); // LLONG_MIN and LLONG_MAX are defined in <climits>
    }
};
