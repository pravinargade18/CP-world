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
private:
    TreeNode* minVal(TreeNode* root){
        TreeNode* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
       


        if(root==NULL){
            return root;
        }

        if(root->val==key){
            // 0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            // 1 child

            // left exist
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;

            }

            // right NULL
             if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;

            }
            // 2 childs
            if(root->left!=NULL && root->right!=NULL){
                // find minimum value from root->right or find max from root->left 
                int mini=minVal(root->right)->val;

                // copy mini into root->data

                root->val=mini;

                // delete that node whose value we have copied into root->data and that node is present on right side of root so call on right side
                root->right=deleteNode(root->right,mini);
             


            }
        }

        else if(key<root->val){
            root->left=deleteNode(root->left,key);
            
        }

        else{
            root->right=deleteNode(root->right,key);
           
        }
        
         return root;
    }

    
};
