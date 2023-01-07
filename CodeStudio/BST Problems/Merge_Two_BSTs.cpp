#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

void inorder(TreeNode<int>*root,vector<int>&v){
    if(root==NULL){
        return ;
    }
    
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

vector<int>mergeInorder(vector<int>a,vector<int>b){
    vector<int>ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
            
        }
        else {
            ans[k++]=b[j++];
            
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
        
    }
    while(j<b.size()){
        ans[k++]=b[j++];
        
    }
    return ans;
}

TreeNode<int> *buildBST(vector<int>&ans,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode<int>* root=new TreeNode<int>(ans[mid]);
    root->left=buildBST(ans,start,mid-1);
    root->right=buildBST(ans,mid+1,end);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    
    vector<int>ans=mergeInorder(bst1,bst2);
    return buildBST(ans,0,ans.size()-1);
}
