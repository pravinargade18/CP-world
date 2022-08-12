class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
            
        }
        for(auto i:m){
            if(i.second>=2){
                return true;
            }
            }
        return false;
        
    
    }
};


//approach 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(auto i:nums){
            s.insert(i);
        }
        return s.size()!=nums.size();
    }
};


//approach 3
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=1;
        for(int i=0;i<nums.size()-1;i++){
            
                if(nums[i]==nums[j]){
                    return true;
                    break;
                }
            j++;
            
        }
        return false;
    }
};
