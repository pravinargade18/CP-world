class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int>v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                v.push_back(arr[i]);
                
            }
        }
       return v;
    }
};
