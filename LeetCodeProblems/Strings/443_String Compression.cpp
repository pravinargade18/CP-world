class Solution {
public:
    int compress(vector<char>& chars) {
        int ansIndex=0;
        int i=0;
        while(i<chars.size()){
            int j=i+1;
            //check until next element changes. till we will increment j 
            while(j<chars.size() && chars[i]==chars[j]){
                j++;
            }
            
            int count=j-i;
            // we will find count of that character
            chars[ansIndex++]=chars[i];
            // if the count is greater than 1 then we have to store the count as well and if count is two digit then we have to store it digit by digit then we will convert it into string and then we will insert it next to character index. 
            if(count>1){
                string s=to_string(count);
                for(char i: s){
                    chars[ansIndex++]=i;
                }
            }
            
            i=j;   //to start for next character
        }
        return ansIndex;
        
    }
};
