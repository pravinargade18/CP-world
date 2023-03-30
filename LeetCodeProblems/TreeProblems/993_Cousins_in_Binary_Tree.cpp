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
    int x_parent=-1;
    int y_parent=-1;
    int x_level=-1;
    int y_level=-1;
    
    void solve(TreeNode* root,int x,int y,int level,int parent){
        if(root==NULL){
            return;
        }
        
        if(root->val==x){
            x_parent=parent;
            x_level=level;
        }
        if(root->val==y){
            y_parent=parent;
            y_level=level;
        }
        solve(root->left,x,y,level+1,root->val);
        solve(root->right,x,y,level+1,root->val);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,x,y,0,-1);
        if(x_level==y_level && x_parent!=y_parent)
            return true;
        return false;
    }
};
