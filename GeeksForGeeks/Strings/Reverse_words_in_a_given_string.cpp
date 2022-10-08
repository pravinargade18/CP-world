class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int i=0;
        stack<string>st;
        while(i<s.length()){
            string temp="";
            while(s[i]!='.' && i<s.length()){
                temp+=s[i];
                i++;
            }
            
            if(temp.length()!=0){
                st.push(temp);
                i++;
                
            }
            
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+='.';
            }
            
        }
        return ans;
    } 
};
