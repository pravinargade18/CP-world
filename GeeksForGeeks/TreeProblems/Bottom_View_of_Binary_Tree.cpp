
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector <int>ans;
        
        if(root==NULL){
            return ans;
        }
        
        map<int,int>mp;
        queue<pair<Node* ,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            pair<Node* ,int> temp=q.front();
            q.pop();
            
            Node* frontNode=temp.first;
            int hd=temp.second;
            
            // if(mp.find(hd)==mp.end()){   here in bottom view we have to remove the condition because we have to overwrite the values in map because we have to take last value
                mp[hd]=frontNode->data;
            // }
            
            if(frontNode->left){
                q.push({frontNode->left,hd-1});
            }
            if(frontNode->right){
                q.push({frontNode->right,hd+1});
            }
        }
        
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};
