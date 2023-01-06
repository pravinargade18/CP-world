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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*>q;
        ans.push_back({root->val});
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;

            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();

                if(front->left){
                    v.push_back(front->left->val);
                    q.push(front->left);
                }
                if(front->right){
                    v.push_back(front->right->val);
                    q.push(front->right);
                }
            
            }
            if(v.size()!=0){
                ans.push_back(v);
            }
            
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};
