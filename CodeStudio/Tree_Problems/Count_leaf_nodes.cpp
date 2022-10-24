/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
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
    
***********************************************************/
void postorder(BinaryTreeNode<int> *root,int &count){
    if(root==NULL){
        return;
    }
    postorder(root->left,count);
    postorder(root->right,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count=0;
    postorder(root,count);
    return count;
}
