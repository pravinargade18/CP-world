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
    int countNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
    bool isCBT(TreeNode* root,int index,int nodeCount){
        if(root==NULL){
            return true;
        }
        if(index>=nodeCount){
            return false;
        }
        else{
            return isCBT(root->left,2*index+1,nodeCount) && isCBT(root->right,2*index+2,nodeCount);
        }
    }
    
    bool isMinHeap(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return root->val<root->left->val;
        }
        else{
            bool left=isMinHeap(root->left);
            bool right=isMinHeap(root->right);
            return left&& right && root->val<root->left->val && root->val<root->right->val;
        }
        
    }
    bool isCompleteTree(TreeNode* root) {
        int nodeCount=countNodes(root);
        int index=0;
        return isCBT(root,index,nodeCount) && isMinHeap(root);
    }
};
