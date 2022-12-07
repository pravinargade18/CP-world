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
        int ans;
    void solve(TreeNode* root, int k,int &i){
        if(root==NULL)
            return  ;
        
        solve(root->left,k,i);
        i++;
        if(i==k){
            ans=root->val;
        }
        solve(root->right,k,i);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        solve(root,k,cnt);
        return ans;
    }
};
