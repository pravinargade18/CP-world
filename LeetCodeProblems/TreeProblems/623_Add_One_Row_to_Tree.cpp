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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            cnt++;
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                //push the data until we reach to needed depth
                if(cnt!=depth-1){
                    if(front->left){
                        q.push(front->left);
                    }
                    if(front->right){
                        q.push(front->right);
                    }
                 }
                else{
                    TreeNode* newNode1=new TreeNode(val);
                    
                        newNode1->left=front->left;
                        front->left=newNode1;
                    
                    TreeNode* newNode2=new TreeNode(val);
                    
                        newNode2->right=front->right;
                        front->right=newNode2;
                    
                }
                
            }
            
        }
        return root;
    }
};
