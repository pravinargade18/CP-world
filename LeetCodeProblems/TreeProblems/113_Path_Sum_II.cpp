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
    vector<vector<int>>ans;
    vector<int>v;
    void solve(TreeNode* root,int targetSum){
        if(root==NULL){
            return ;
        }
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(accumulate(v.begin(),v.end(),0)==targetSum){
                ans.push_back(v);
                
            }
        }
        solve(root->left,targetSum);
        solve(root->right,targetSum);
        v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        solve(root,targetSum);
        return ans;
    }
};
