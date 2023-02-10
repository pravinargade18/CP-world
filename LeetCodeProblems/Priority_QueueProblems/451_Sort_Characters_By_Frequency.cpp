class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>pq;
        for(auto i:s){
            m[i]++;
        }
        
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        s="";
        
        while(!pq.empty()){
            s+=string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return s;
    }
};
