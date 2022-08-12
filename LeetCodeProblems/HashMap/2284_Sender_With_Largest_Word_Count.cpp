class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
       map<string,int>m;
        for(int i=0;i<senders.size();i++){
            int cnt=0;
            for(int j=0;j<messages[i].length();j++){
                if(messages[i][j]==' '){
                    cnt++;
                }
            }
            cnt++;
             m[senders[i]]+=cnt;
        }
        int maxi= 0;
        string sender;
        for(auto i:m){
            if(i.second>=maxi){
                maxi=i.second;
                sender=i.first;
            }
        }
        
        
        return sender;
        
        
        
    }
};
