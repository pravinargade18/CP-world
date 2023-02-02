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
    TreeNode* constructBT(vector<int>&v,int s,int e){
        if(s>e){
            return NULL;
        }
        int index=-1;
        int val=INT_MIN;
        for(int i=s;i<=e;i++){
            if(v[i]>val){
                index=i;
                val=v[i];
            }
        }
        TreeNode* root=new TreeNode(val);
        root->left=constructBT(v,s,index-1);
        root->right=constructBT(v,index+1,e);
        return root;
    }
    

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructBT(nums,0,nums.size()-1);
        
    }
};
