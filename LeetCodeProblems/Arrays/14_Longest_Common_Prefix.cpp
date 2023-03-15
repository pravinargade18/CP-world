class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        char ch;
        string ans="";
        for(int i=0;i<arr[0].size();i++){
            ch=arr[0][i];
            bool match=true;

            for(int j=1;j<arr.size();j++){
                if(arr[j].size()<i || ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            
            if(match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
