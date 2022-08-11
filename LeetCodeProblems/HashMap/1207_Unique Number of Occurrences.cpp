class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        set<int> s;
        for(auto it:arr){
            m[it]++;
        }
        for(auto i:m){
            s.insert(i.second);
        }
        if(s.size()==m.size()){
            return true;
        }
        else{
            return false;
        }
        
    }
};
