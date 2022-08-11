class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        int size=nums.size();
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(nums[i]+nums[j]==target){
                    arr.push_back(i);
                    arr.push_back(j);
                    return arr;
                }
            
            }
        }
        return arr;
        
    }
};
