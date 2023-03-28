class comparator{
    public:
        bool operator()(pair<int,string>a,pair<int,string>b){
            if(a.first<b.first) return true;  //size of first stirng 
            else if(a.first==b.first && a.second>b.second) return true;
            return false;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>m;
        for(auto i:words){
            m[i]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator>pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        return ans;
        
    }
};
