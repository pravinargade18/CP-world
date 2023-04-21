class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>ans(score.size(),"");
        
        for(int i=0;i<score.size();i++){
            if(i==0){
                ans[pq.top().second]="Gold Medal";
                pq.pop();
            }
            else if(i==1){
                ans[pq.top().second]="Silver Medal";
                pq.pop();
            }
            else if(i==2){
                ans[pq.top().second]="Bronze Medal";
                pq.pop();
            }
            else{
                ans[pq.top().second]=to_string(i+1);
                pq.pop();
            }
        }
        return ans;
    }
};
