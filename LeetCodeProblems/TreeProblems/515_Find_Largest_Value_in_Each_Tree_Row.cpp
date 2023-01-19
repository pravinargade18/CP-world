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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        
        q.push(root);
        // ans.push_back(root->val);
        
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->val>maxi){
                    maxi=front->val;
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
