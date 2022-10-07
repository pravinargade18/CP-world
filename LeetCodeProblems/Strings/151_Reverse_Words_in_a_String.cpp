class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int i=0;
        while(i<s.length()){
            while(s[i]==' ' && i<s.length()){
                i++;
            }
            string temp="";
            while(s[i]!=' ' && i<s.length()){
                temp+=s[i];
                i++;
                
            }
            if(temp.length()!=0){
                st.push(temp);
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                 ans+=' ';
            }
        }
        return ans;
    }
};
