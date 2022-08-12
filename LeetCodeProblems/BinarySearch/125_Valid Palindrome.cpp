class Solution {
public:
    // char toLowerCase(char ch){
    //     if((ch>='a' && ch<='z') || (ch>=0 && ch<=9)){
    //         return ch;
    //     }
    //     else{
    //         ch=ch-'A'+'a';   //
    //         return ch;
    //     }
    // }
    
    bool isPalindrome(string str) {
        int s=0;
        int e=str.length()-1;
        while(s<=e){
        if(!isalnum(str[s])){
            s++;
        }
        else if(!isalnum(str[e])){
            e--;
        }
        else if(tolower(str[s])!=tolower(str[e])){
            // here we can use tolower inbuilt function or the function which we have created above
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
    }
};
