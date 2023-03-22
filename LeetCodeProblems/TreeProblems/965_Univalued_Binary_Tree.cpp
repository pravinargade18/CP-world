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
    bool solve(TreeNode* root,int rootData){
        if(root==NULL){
            return true;
        }
        if(root->val!=rootData){
            return false;
        }
        
        return solve(root->left,rootData)&& solve(root->right,rootData);
    }
    bool isUnivalTree(TreeNode* root) {
        int rootData=root->val;
        return solve(root,rootData);
        
    }
};
