class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
            
        }
        for(auto j:m){
            if(j.second==1){
                return j.first;
            }
        }
        return -1;
    }
};


approach -2 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
       for(int i=0;i<n;i++){
           ans=ans^nums[i];
       }
        return ans;
    }  
};
