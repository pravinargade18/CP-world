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


// Efficient approach
class Solution {
public:
    int thirdMax(vector<int>& arr) {
        long long int first=LONG_MIN;
        long long int second=LONG_MIN;
        long long int third=LONG_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==first || arr[i]==second || arr[i]==third){   //to avoid duplicate elements
                continue;
            }
            if(arr[i]>first){
                third=second;     //third will be second means thrid maximum
                second=first;       //second will become first means second maximum
                first=arr[i];     // first will become maximum one
            }
            
            else if(arr[i]>second){
                third=second;
                second=arr[i];
            }
            else if(arr[i]>third){
                third=arr[i];
            }
        }
        return third==LONG_MIN?first:third;
        
    }
};
