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
    TreeNode* createMapping(TreeNode* root,int start,map<TreeNode*,TreeNode*>&m){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* startNode=NULL;
        m[root]=NULL;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            
            if(front->val==start){
                startNode= front;
            }
            if(front->left){
                q.push(front->left);
                m[front->left]=front;
                
            }
            if(front->right){
                q.push(front->right);
                m[front->right]=front;
            }
        }
        return startNode;
    }
    
    void infection(TreeNode* start,int &time,map<TreeNode*,TreeNode*>&nodeToParent){
        map<TreeNode*,bool>visited;
        visited[start]=1;
        queue<TreeNode*>q;
        q.push(start);
        
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                TreeNode* root=q.front();
                q.pop();
                if(root->left && !visited[root->left]){
                flag=1;
                q.push(root->left);
                visited[root->left]=1;
            }
            if(root->right && !visited[root->right]){
                flag=1;
                q.push(root->right);
                visited[root->right]=1;
            }
            
            if(nodeToParent[root] && !visited[nodeToParent[root]]){
                flag=1;
                q.push(nodeToParent[root]);
                visited[nodeToParent[root]]=1;
                }
            }
            
            
            if(flag==1){
                time++;
            }
        }
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>nodeToParent;
        TreeNode* startingNode=createMapping(root,start,nodeToParent);
        int time=0;
        infection(startingNode,time,nodeToParent);
        return time;
        
        
    }
};
