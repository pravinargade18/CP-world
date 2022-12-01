

// Function to search a node in BST.
bool search(Node* root, int x) {
    if(root==NULL){
        return NULL;
        
    }
    if(root->data==x){
        return root;
        
    }
    if(x<root->data){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}
