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
    TreeNode* traversal(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        if(root1!=NULL && root2==NULL){
            return root1 ;
        }
        if(root2!=NULL && root1==NULL){
            
            return root2 ;
        }
        root1->val=root1->val+root2->val;
        root1->left=traversal(root1->left,root2->left);
        root1->right=traversal(root1->right,root2->right);
        
        return root1;
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       return  traversal(root1,root2);
       
    }
};
