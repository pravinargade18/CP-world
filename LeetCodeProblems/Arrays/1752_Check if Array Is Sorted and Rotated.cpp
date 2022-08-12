class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%n])count++;
            // This case considers last element and first elements case too.
            
        }
        
        return count<=1;
    }
};


//approach-2
class Solution {
public:
    bool check(vector<int>& nums) {
    int Countpair=0;
    int n=nums.size();
    
    // Since there will exist only one pair in which i-1>i;
    
    for(int i=1;i<n;i++){
        
        if(nums[i-1]>nums[i]){
            Countpair++;  
        }  
    }
    // it is for checking last element with first element
    if(nums[n-1]>nums[0]){
            Countpair++;
        }
    
    return Countpair<=1;
}
};
