class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto j:m){
            if(j.second>nums.size()/2){
                return j.first;
            }
            
        }
        return -1;
    }
};
