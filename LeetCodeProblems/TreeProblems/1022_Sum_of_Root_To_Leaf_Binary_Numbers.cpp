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
    int sum=0;
    void solve(TreeNode* root,string temp){
        if(root==NULL){
            return;
        }
        temp+=to_string(root->val);
        
        if(root->left==NULL && root->right==NULL){
           sum+=stoi(temp,0,2);
        }
        solve(root->left,temp);
        solve(root->right,temp);
        temp.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string temp="";
        solve(root,temp);
        return sum;
    }
};
