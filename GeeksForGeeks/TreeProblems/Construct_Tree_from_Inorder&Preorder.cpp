

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
        void createMapping(map<int,int>&m,int in[],int n){
            for(int i=0;i<n;i++){
                m[in[i]]=i;
            }
        }
        Node* solve(int in[],int pre[],int inStart,int inEnd,int &index,int n,map<int,int>&m){
            
            if(index>=n || inStart>inEnd){
                return NULL;
            }
            
            int element=pre[index++]; //select the element in preorder array 
            Node* root=new Node(element);
            int position=m[element];
            
            root->left=solve(in,pre,inStart,position-1,index,n,m);
            root->right=solve(in,pre,position+1,inEnd,index,n,m);
            
            return root;
            
        }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preStart=0;
        int inStart=0;
        int inEnd=n-1;
        map<int,int>m;
        createMapping(m,in,n);
        Node* root=solve(in,pre,inStart,inEnd,preStart,n,m);
        return root;
    }
};
