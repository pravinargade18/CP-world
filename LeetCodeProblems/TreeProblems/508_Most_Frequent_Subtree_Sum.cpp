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
    unordered_map<int,int>m;
    int sumAtNode(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return root->val+sumAtNode(root->left)+sumAtNode(root->right);
        
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorder(root->left);
        m[sumAtNode(root)]++;
        inorder(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        inorder(root);
        vector<int>v;
        int maxi=INT_MIN;
        for(auto i:m){
            if(i.second>maxi){
                maxi=i.second;
                v.clear();
                v.push_back(i.first);
            }
            else if(i.second==maxi){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
