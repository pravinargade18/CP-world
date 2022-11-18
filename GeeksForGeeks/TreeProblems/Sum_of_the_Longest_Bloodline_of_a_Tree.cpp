
/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
private:
    void solve(Node* root,int &maxSum,int& maxLen,int len,int sum){
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }
            else if(len==maxLen){
                maxSum=max(sum,maxSum);
            }
            
            return;
        }
        
        sum+=root->data;
        solve(root->left,maxSum,maxLen,len+1,sum);
        solve(root->right,maxSum,maxLen,len+1,sum);
    
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len=0;
        int sum=0;
        int maxSum=0;
        int maxLen=0;
        solve(root,maxSum,maxLen,len,sum);
        return maxSum;
    }
};
