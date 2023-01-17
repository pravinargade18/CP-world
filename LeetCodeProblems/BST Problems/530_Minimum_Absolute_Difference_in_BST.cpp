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
    int mini=INT_MAX;
    int val=100000000;
    int diff;
    int minDiff(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        minDiff(root->left);
        diff=abs(root->val-val);
        mini=min(mini,diff);
        val=root->val;
        minDiff(root->right);
        return mini;
    }
    int getMinimumDifference(TreeNode* root) {
        return minDiff(root);
        
    }
};
