class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[cnt]=nums[i];
                cnt++;
            }
        }
        return cnt;
        
    }
};


//APPROACH 2
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return remove(nums.begin(), nums.end(), val)-nums.begin();
        
    }
};
