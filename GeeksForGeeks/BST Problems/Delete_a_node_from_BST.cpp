

// Function to delete a node from BST.
Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node *deleteNode(Node *root, int X) {
    if(root==NULL){
        return root;
    }
    if(root->data==X){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 child
        
        // left child exist
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        // right child exist
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // 2 childs
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteNode(root->right,mini);
            return root;
            
        }
    }
    else if(X<root->data){
        root->left=deleteNode(root->left,X);
        return root;
    }
    else{
        root->right=deleteNode(root->right,X);
        return root;
    }
}
