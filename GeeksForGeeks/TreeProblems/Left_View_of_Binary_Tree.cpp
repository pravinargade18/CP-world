
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

void solve(Node* root,vector<int>& ans ,int level){
    if(root==NULL){
        return ;
    }
    
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   int level=0;
   solve(root,ans,level);
   return ans;
}
