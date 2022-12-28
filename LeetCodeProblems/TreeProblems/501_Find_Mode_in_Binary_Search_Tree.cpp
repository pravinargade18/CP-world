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
    void inorder(TreeNode* root,map<int,int>&m){
        if(root==NULL){
            return ;
        }
        inorder(root->left,m);
        m[root->val]++;
        inorder(root->right,m);
    }
public:
    vector<int> findMode(TreeNode* root) {
       
        map<int,int>m;
        inorder(root,m);
        vector<int>v;
        int maxi=INT_MIN;
        for(auto i:m){
            if(i.second>maxi){
                maxi=i.second;
            }
        }
            for(auto i:m){
                if(i.second==maxi){
                    v.push_back(i.first);
                }
         }
        
        
        return v;
    }
};
