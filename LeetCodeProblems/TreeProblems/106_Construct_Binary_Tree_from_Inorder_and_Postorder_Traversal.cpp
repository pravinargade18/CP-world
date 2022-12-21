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
    void createMapping(map<int,int>&m,int size,vector<int> inorder){
        for(int i=0;i<size;i++){
            m[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,map<int,int>&m,int size,int &index){
        if(index<0 || inStart>inEnd){
            return NULL;
        }
        
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);
        
        int position=m[element];
        
        root->right=solve(inorder,postorder,position+1,inEnd,m,size,index);
        root->left=solve(inorder,postorder,inStart,position-1,m,size,index);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        int postIndex=postorder.size()-1;
        int inStart=0;
        int inEnd=size-1;
        map<int,int>m;
        createMapping(m,size,inorder);
        TreeNode* root=solve(inorder,postorder,inStart,inEnd,m,size,postIndex);
        return root;
    }
};
