class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isValidBST(Node* root,int min,int max){
        if(root==NULL){
            return true;
        }
        
        if(root->data>=min && root->data<=max){
            bool left=isValidBST(root->left,min,root->data);
            bool right=isValidBST(root->right,root->data,max);
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isBST(Node* root) 
    {
        return isValidBST(root,INT_MIN,INT_MAX);
    }
};

