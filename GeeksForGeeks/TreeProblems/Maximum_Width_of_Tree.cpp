/*  Structure of a Binary Tree

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

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {

       queue<Node*>q;
       q.push(root);
       int maxSize=INT_MIN;
       while(!q.empty()){
           int size=q.size();
           maxSize=max(maxSize,size);
           for(int i=0;i<size;i++){
               Node* front=q.front();
               q.pop();
               if(front->left){
                   q.push(front->left);
               }
               if(front->right){
                   q.push(front->right);
               }
           }
       }
       return maxSize;
    }
};
