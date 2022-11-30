#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
        BinaryTreeNode<int> *temp=root;
        while(temp!=NULL){
            if(temp->data==x){
                return true;
            }
        
            if(x<temp->data){
                return searchInBST(root->left,x);
            }
            else{
                return searchInBST(root->right,x);
            }
        }
    return false;
        
}

//another approach

#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
   if(root==NULL){
            return false;
        }
        
        if(x==root->data){
            return true;
        }
        
        if(x<root->data){
            searchInBST(root->left,x);
        }
        else{
            searchInBST(root->right,x);
        }
}
