class Solution {
private:
    int length(string str,string str1){
        int arr[26]={false};
        for(int i=0;i<str.length();i++){
            arr[str[i]-'a']=true;
        }
        for(int i=0;i<str1.length();i++){
            if(arr[str1[i]-'a']==true){
                return 0;
            }
        }
        return str.length()*str1.length();
    }
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(ans<(words[i].length()*words[j].length())){
                ans=max(ans,length(words[i],words[j]));
                }
            }
        }
            
        return ans;
    }
};
