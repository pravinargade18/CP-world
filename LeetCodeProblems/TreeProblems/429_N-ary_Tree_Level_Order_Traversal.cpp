/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        
        queue<Node*>q;
        ans.push_back({root->val});
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;

            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();

                for(auto j:front->children){
                    q.push(j);
                    v.push_back(j->val);
                }
            
            }
            if(v.size()!=0){
                ans.push_back(v);
            }
            
        }
        return ans;
    }
};
