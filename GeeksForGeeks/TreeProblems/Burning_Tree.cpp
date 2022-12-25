//User function Template for C++

class Solution {
    private:
   Node* createMapping(Node* root,int target,
    map<Node*, Node*> &nodeToparent)
    {
        Node* res=NULL;
        queue<Node*>q;
        q.push(root);
        nodeToparent[root]=NULL;
        while(!q.empty())
        {
            Node* front=q.front();
            q.pop();
            
            if(front->data==target){
                res=front;
            }
            if(front->left){
                nodeToparent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodeToparent[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int BurnTime(map<Node*,Node*>&nodeToParent,Node* root){
        map<Node*,bool>visited;
        queue<Node*>q;
        
        visited[root]=1;
        q.push(root);
            int ans=0;
        while(!q.empty()){
            int size=q.size();
                bool flag=0;
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    flag=1;
                    q.push(front->left);
                    visited[front->left]=1;
                }
                
                 if(front->right && !visited[front->right]){
                     flag=1;
                    q.push(front->right);
                    visited[front->right]=1;
                }
                
                 if(nodeToParent[front] && !visited[nodeToParent[front]]){
                     flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=1;
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
    }
    
    
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*>nodeToParent;
        
        Node* targetNode=createMapping(root,target,nodeToParent);
        int ans=BurnTime(nodeToParent,targetNode);
        return ans;
    }
};
