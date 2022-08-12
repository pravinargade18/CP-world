class Solution {
public:
    
    void reverse(vector<char> &s,int i,int j){
        if(i>j){
            return ;
        }
        swap(s[i++],s[j--]);
        reverse(s,i,j);
    }
    void reverseString(vector<char>& str) {
        reverse(str,0,str.size()-1);
        
    }
};
