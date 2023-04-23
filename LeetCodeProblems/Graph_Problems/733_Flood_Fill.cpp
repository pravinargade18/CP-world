class Solution {
private:
    void dfs(vector<vector<int>>&ans,vector<vector<int>>&image,int initialColor,int color,int row,int col,int delrow[],int delcol[]){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==initialColor ){
                dfs(ans,image,initialColor,color,nrow,ncol,delrow,delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,+1,0};   //to traverse left right up down 
        int delcol[]={0,+1,0,-1};
        dfs(ans,image,initialColor,color,sr,sc,delrow,delcol);
        return ans;
        
    }
};
