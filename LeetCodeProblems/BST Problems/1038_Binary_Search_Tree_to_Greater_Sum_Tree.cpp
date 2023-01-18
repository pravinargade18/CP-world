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
    void solve(TreeNode* root,int &rightPart){
         if(root==NULL){
            return ;
        }
        
        solve(root->right,rightPart);
        root->val+=rightPart;
        rightPart=root->val;
        solve(root->left,rightPart);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int rightPart=0;
        solve(root,rightPart);
        return root;
        
        
    }
};
