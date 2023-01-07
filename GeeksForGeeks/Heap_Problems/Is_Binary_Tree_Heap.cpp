// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(struct Node* root){
        if(root==NULL){
            return 0;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
        
    }
    
    bool isCBT(struct Node* root,int index,int nodeCount){
        if(root==NULL){
            return true;
        }
        if(index>=nodeCount){
            return false;
        }
        else{
            return isCBT(root->left,2*index+1,nodeCount)&& isCBT(root->right,2*index+2,nodeCount);
        }
    }
    
    bool isMaxHeap(struct Node* root){
        if(!root->left && !root->right){
            return true;
        }
        if(!root->right){
            return root->data>root->left->data;
        }
        else{
            bool left=isMaxHeap(root->left);
            bool right=isMaxHeap(root->right);
            return left && right && root->data>root->left->data && root->data>root->right->data;
        }
    }
    bool isHeap(struct Node* tree) {
        int nodeCount=countNodes(tree);
        int index=0;
        //two conditions to be checked is complete binary tree and it follows maxheap property then true else false
        return isCBT(tree,index,nodeCount) && isMaxHeap(tree);
        
        
    }
};
