

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void createMapping(map<int,int>&m,int n,int in[]){
    for(int i=0;i<n;i++){
        m[in[i]]=i;
    }
}
Node* solve(int in[],int post[],int inStart,int inEnd,int &index,int n,map<int,int>&m){
    if(index<0 || inStart>inEnd){
        return NULL;
    }
    int element=post[index--];
    Node* root=new Node(element);
    int position=m[element];
    
    root->right=solve(in,post,position+1,inEnd,index,n,m);
    root->left=solve(in,post,inStart,position-1,index,n,m);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int postIndex=n-1;
    int inStart=0;
    int inEnd=n-1;
    map<int,int>m;
    createMapping(m,n,in);
    Node* root=solve(in,post,inStart,inEnd,postIndex,n,m);
    return root;
}
