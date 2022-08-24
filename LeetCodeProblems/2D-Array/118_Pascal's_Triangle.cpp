class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);          // initialize n rows        
        for(int i = 0; i < n; i++) {
            ans[i].resize(i+1);              // ith row(0-indexed) has i+1 elements
            ans[i][0] = ans[i][i] = 1;       // first and last element of the row will be 1
            
            for(int j = 1; j < i; j++)       // calc the sum of two elements from above row 
                ans[i][j] = ans[i - 1][j-1] + ans[i - 1][j];            
        }
        return ans;
    }
};
