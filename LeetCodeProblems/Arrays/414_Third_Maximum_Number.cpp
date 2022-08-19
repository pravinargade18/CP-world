// Naive approach
class Solution {
public:
    int thirdMax(vector<int>& nums) {
         int cnt=1;
        sort(nums.begin(), nums.end(), greater<int>());
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<maxi ){
                maxi=nums[i];
                cnt++;
            }
            if(cnt==3){
                return nums[i];
            }
        }
        return nums[0];
        
        
    }
};
