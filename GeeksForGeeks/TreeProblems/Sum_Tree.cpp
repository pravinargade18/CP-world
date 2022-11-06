struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
        pair<bool,int>isSumTreeFast(Node* root){
            if(root==NULL){
                pair<bool,int>p=make_pair(true,0);
                return p;
            }
            
            if(root->left==NULL && root->right==NULL){
                pair<bool,int>p=make_pair(true,root->data);  //root->data because for leaf node sum will be that nodes data only
                return p;
            }
            
            pair<bool,int> left=isSumTreeFast(root->left);
            pair<bool,int> right=isSumTreeFast(root->right);
            
            // conditions to be true
            bool leftAns=left.first;
            bool rightAns=right.first;
            
            bool condition=(left.second+right.second)==root->data;
            
            pair<bool,int>ans;
            if(leftAns && rightAns && condition){
                // if all these conditions are true then ans will be 
                ans.first=true;
                ans.second=left.second+right.second+root->data;
            }
            
            else{
                ans.first=false;
            }
            return ans;
            
            
            
        }
    public:
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};
