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
public:
    int sum=0;
    int solve(TreeNode* root,string s){
        if(root==NULL){
            return 0;
        }
        s+=to_string(root->val);
        if(!root->left && !root->right){
            sum=stoi(s);
            return sum;
        }
        return solve(root->left,s)+solve(root->right,s);
        
        
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        return solve(root,s);
    }
};

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
public:
    int solve(TreeNode* root,int sum){
        if(root==NULL){
            return 0;
        }
        sum=sum*10+root->val;
        if(!root->left && !root->right){
            return sum;
        }
        return solve(root->left,sum)+solve(root->right,sum);
        
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        return solve(root,sum);
    }
};
