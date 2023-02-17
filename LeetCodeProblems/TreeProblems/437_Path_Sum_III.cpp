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
        void solve(TreeNode* root ,int targetSum ,vector<int>v,int &count){
            if(root==NULL){
                return ;
            }
            v.push_back(root->val);
            solve(root->left,targetSum,v,count);
            solve(root->right,targetSum,v,count);
            int size=v.size();
            long long sum=0;
            for(int i=size-1;i>=0;i--){
                sum+=v[i];
                if(sum==targetSum){
                    count++;
                }
            }
            v.pop_back();
        }
        int pathSum(TreeNode* root, int targetSum) {
            int count=0;
            vector<int>v;
            solve(root,targetSum,v,count);
            return count;
        }
};
