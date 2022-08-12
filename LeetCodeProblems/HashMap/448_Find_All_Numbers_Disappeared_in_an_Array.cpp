class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size=nums.size();
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=1;i<=size;i++){
            m[i]=0;
        }
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second==0){
                v.push_back(i.first);
            }
        }
            

        
        return v;
}
};
