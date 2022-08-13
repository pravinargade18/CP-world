class Solution{
  public: 
       vector<int> duplicates(int arr[], int n) {
       unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(auto j:m){
            if(j.second>1){
                v.push_back(j.first);
            }
        }
        
        sort(v.begin(),v.end());
        if(v.empty()){
            return {-1};
        }
        return v;
    }
    
};
