class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 1;
         int i = 0;
         int ans = -1;
         int count = 0;
         int n = arr.size();
         while(j <= n + k)
         {
             if(j != arr[i])
             {
                 count++;
                 // cout<<j;
                 if(count == k)
                 {
                     return j;
                 }
                 
             }
             else
             {
                if(i != n - 1)
                    i++;
             }
             j++;
         }
        return ans;
    
    }
};
