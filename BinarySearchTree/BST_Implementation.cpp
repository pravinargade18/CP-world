
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

Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root,int val){
    if(root==NULL){
        return root;
    }
    
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        // 1 child
        
        // left exist
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
            
        }
        
        // right NULL
         if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
            
        }
        // 2 childs
        if(root->left!=NULL && root->right!=NULL){
            // find minimum value from root->right or find max from root->left 
            int mini=minVal(root->right)->data;
            
            // copy mini into root->data
            
            root->data=mini;
            
            // delete that node whose value we have copied into root->data and that node is present on right side of root so call on right side
            root->right=deleteFromBST(root->right,mini);
            return root;
            
            
        }
    }
    
    else if(val<root->data){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
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

    //Deletion
    root=deleteFromBST(root,90);
    
    // 50 20 70 10 30 90 110 -1
    cout<<endl;
    cout<<endl;
    cout<<"DELETION"<<endl;
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
