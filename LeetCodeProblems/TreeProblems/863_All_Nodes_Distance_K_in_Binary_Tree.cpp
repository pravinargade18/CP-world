 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createMapping(TreeNode* root,map<TreeNode*,TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(root);
        m[root]=NULL;
        // TreeNode* targetNode=NULL;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            // if(front->val==target->val){
            //     targetNode=target->val;
            // }
            if(front->left){
                m[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                m[front->right]=front;
                q.push(front->right);
            }
        }
        
    }
    vector<int> findValues(TreeNode* root,int k,map<TreeNode*,TreeNode*>&m){
        map<TreeNode*,bool>visited;
        visited[root]=true;
        queue<TreeNode*>q;
        q.push(root);
        int current_level=0;
        while(!q.empty()){
            int size=q.size();
            if(current_level==k){
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && !visited[front->left] ){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right && !visited[front->right] ){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(m[front] && !visited[m[front]]){
                    q.push(m[front]);
                    visited[m[front]]=true;
                }
            }
            current_level++;
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front()->val;
            ans.push_back(front);
            q.pop();
        }
        return ans;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>nodeToParent;
        createMapping(root,nodeToParent);
        return findValues(target,k,nodeToParent);
    }
};
