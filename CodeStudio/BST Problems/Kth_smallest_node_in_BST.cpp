#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int> *root, int k,int &i){
    if(root==NULL){
        return -1;
    }
    
    int left=solve(root->left,k,i);
    
    if(left!=-1){
        return left;
    }
    i++;
    if(k==i){
        return root->data;
    }
    
    return solve(root->right,k,i);
    
    
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int i=0;
    int ans=solve(root,k,i);
    return ans;
}
