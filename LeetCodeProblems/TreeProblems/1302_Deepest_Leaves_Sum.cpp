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
     int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    int levelOrder(TreeNode* root,int level){
        queue<TreeNode*>q;
        q.push(root);
        int count=1;
        while(!q.empty()){
            int size=q.size();
            if(count==level){
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                
            }
            count++;
        }
        int sum=0;
        while(!q.empty()){
            int front=q.front()->val;
            q.pop();
            sum+=front;
        }
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        int level=maxDepth(root);
        return levelOrder(root,level);
        
    }
   
};

//Approach 2
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
    int sum=0;
    int maxDepth=INT_MIN;
    void findSum(TreeNode* root,int depth){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(depth>maxDepth){
                maxDepth=depth;
                sum=root->val;
            }
            else if(depth==maxDepth){
                sum+=root->val;
            }
            
        }
        findSum(root->left,depth+1);
        findSum(root->right,depth+1);
        
        
    }
    int deepestLeavesSum(TreeNode* root) {
        findSum(root,0);
        return sum;
        
    }
   
};
