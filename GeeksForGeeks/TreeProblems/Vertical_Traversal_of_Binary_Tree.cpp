class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int,map<int,vector<int> > >m;
        queue<pair<Node* ,pair<int,int> > >q;   //every element in q will have node and pair consisting horizontal distance and level of that node
        
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node* ,pair<int,int> >temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;
            
            m[hd][level].push_back(frontNode->data);  //push this data for that hd and level for that particular node
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));
            }
        }
            
            for(auto i:m){
                for(auto j:i.second){
                    for(auto k:j.second){
                        ans.push_back(k);
                    }
                }
            }
            
            return ans;
        
    }
};
