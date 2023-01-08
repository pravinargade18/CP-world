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
    int solve(TreeNode* root,int sum,bool leftLeaf){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL && leftLeaf){
            return root->val;
        }
        
        int left=solve(root->left,sum,true);
        
        int right=solve(root->right,sum,false);
        sum=left+right;
        
        
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        bool left=false;
        return solve(root,sum,left);
        
    }
};
