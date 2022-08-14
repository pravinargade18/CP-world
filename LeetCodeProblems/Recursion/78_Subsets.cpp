class Solution {  
    // detail explanation in notebook
private:
    void solve(vector<int>nums,int index,vector<vector<int>>&ans,vector<int>output){
        // base case
        if(index>=nums.size()){
            ans.push_back(output);  //when the base case reach push the output vector into main ans
            return;
        }
//         exclude the number present at index
        solve(nums,index+1,ans,output);
        
//         include the element present at index
        // detail explanation in notebook
        // first find the element which is to be included that element will be element present at current index
        int element=nums[index];
        output.push_back(element);
        solve(nums,index+1,ans,output);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,0,ans,output);
        return ans;
    }
};
