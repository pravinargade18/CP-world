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
    void solve(TreeNode* rootleft,TreeNode* rootright,int level){
        if(rootleft==NULL && rootright==NULL){
            return;
        }
        if(level%2==0){
            swap(rootleft->val,rootright->val);
        }
        solve(rootleft->left,rootright->right,level+1);
        solve(rootleft->right,rootright->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,0);
        return root;
    }
};
