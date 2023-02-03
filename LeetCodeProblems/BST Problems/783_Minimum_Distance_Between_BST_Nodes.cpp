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
    TreeNode* prev=NULL;
    int diff=INT_MAX;
    int inorder(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        inorder(root->left);
        if(prev!=NULL){
            diff=min(diff,root->val-prev->val);
        }
        prev=root;
        inorder(root->right);
        return diff;
    }
    int minDiffInBST(TreeNode* root) {
        return inorder(root);
        
    }
};
