/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        
        int ans=max(left,right)+1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }
        else{ 
            return false;
        }
    }
};


// Added another approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
   pair<bool,int>isBalancedFast(TreeNode* root){
            if(root==NULL){
                pair<bool,int>p=make_pair(true,0);
                return p;
            }
        
        pair<bool,int> left=isBalancedFast(root->left);
        pair<bool,int> right=isBalancedFast(root->right);
        
        bool leftAns=left.first;
        bool rightAns=right.first;
        bool diff=abs(left.second-right.second)<=1;
        
        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first= true;
        }
        else{
            ans.first= false;
        }
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
       return isBalancedFast(root).first;
        }
};

