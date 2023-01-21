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
    TreeNode* first;
    TreeNode* second;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first=prev;
                second=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
   
    void recoverTree(TreeNode* root) {
       first=second=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            swap(first->val,last->val);
        }
        else if(first && second){
            swap(first->val,second->val);
        }
    }
};
