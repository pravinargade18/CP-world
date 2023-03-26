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
    int count=0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        
        int sum=left.first+right.first+root->val;
        int nodes=left.second+right.second+1;
        if(sum/nodes==root->val){
            count++;
        }
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return count;
    }
};
