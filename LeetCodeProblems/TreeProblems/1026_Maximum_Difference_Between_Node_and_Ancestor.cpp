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
    int maxDiff=INT_MIN;
    void solve(TreeNode* root,int mini,int maxi){
        if(root==NULL)
            return ;
        
        if(root->val<mini){
            mini=root->val;
        }
        if(root->val>maxi){
            maxi=root->val;
        }
        maxDiff=max(maxDiff,abs(mini-maxi));
        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini=root->val;
        int maxi=root->val;
        solve(root,mini,maxi);
        return maxDiff;
    }
};
