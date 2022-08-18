//approach 1
class Solution {
    private:
    void solve(vector<int>&nums,int index,vector<vector<int>>&ans){
    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,index+1,ans);
             swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
     
        solve(nums,index,ans);
        sort(begin(ans),end(ans));
        ans.erase(unique(begin(ans), end(ans)),end(ans));
        return ans;
    }
};

//approach 2

class Solution {
 
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do{
            res.push_back(nums);
        }
        while(next_permutation(nums.begin(), nums.end()));
        return res;

    }
};
