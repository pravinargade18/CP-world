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


//approach - 2
class Solution {
public:
    
    // the number accupying more than half space must be somewhere at middle of the array
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
