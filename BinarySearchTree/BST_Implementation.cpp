/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* insertIntoBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    
    if(root->data> d){
        root->right=insertIntoBST(root->right,d);
    }
    
    else{
        root->left=insertIntoBST(root->left,d);
    }
    
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}


int main()
{
    Node* root=NULL;
    cout<<"Enter the data to create BST: "<<endl;
    takeInput(root);
    
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);
    cout <<endl<< "inorder traversal is:  ";
    inorder(root); 
    cout << endl << "preorder traversal is:  ";
    preorder(root); 
    cout << endl << "postorder traversal is:  ";
    postorder(root); 

    return 0;
}
