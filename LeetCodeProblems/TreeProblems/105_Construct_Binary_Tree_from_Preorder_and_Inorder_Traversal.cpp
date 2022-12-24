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
    void createMapping(map<int,int>&m,int size,vector<int>inorder){
        for(int i=0;i<size;i++){
            m[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,int size,int &index,map<int,int>&m){
        if(index>=size || inStart>inEnd){
            return NULL;
        }
        
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int position=m[element];
        
        root->left=solve(preorder,inorder,inStart,position-1,size,index,m);
        root->right=solve(preorder,inorder,position+1,inEnd,size,index,m);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart=0;
        int inEnd=inorder.size()-1;
        int size=inorder.size();
        int preIndex=0;
        map<int,int>m;
        createMapping(m,size,inorder);
        TreeNode* root=solve(preorder,inorder,inStart,inEnd,size,preIndex,m);
        return root;
    }
};
