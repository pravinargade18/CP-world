struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
      void traverseLeft(Node* root,vector<int>&ans){
          if(root==NULL){
              return;
          }
          
        //   if leaf node
          if(root->left==NULL && root->right==NULL){
              return ;
          }
          
          ans.push_back(root->data);
          
          if(root->left){
              traverseLeft(root->left,ans);
          }
          
          else{
              traverseLeft(root->right,ans);
          }
          
      }
      
     void traverseLeaf(Node* root,vector<int>&ans){
         if(root==NULL){
             return;
         }
         
         if(root->left==NULL && root->right==NULL){
             ans.push_back(root->data);
             return;
         }
         
         traverseLeaf(root->left,ans);
         traverseLeaf(root->right,ans);
     }
     
     void traverseRight(Node* root,vector<int>&ans){
         if(root==NULL){
             return;
         }
         
         if(root->left==NULL && root->right==NULL){
             return;
         }
         
         if(root->right){
            traverseRight(root->right,ans);
         }
         else{
            traverseRight(root->left,ans);
         }
         
         ans.push_back(root->data);
     }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        
        
        // traverse leaf nodes
        // traverse left subtree
        traverseLeaf(root->left,ans);
        // traverse right subtree
        traverseLeaf(root->right,ans);
        
        
        // traverse Right part
        traverseRight(root->right,ans);
        
        return ans;
        
        
        
    }
};
