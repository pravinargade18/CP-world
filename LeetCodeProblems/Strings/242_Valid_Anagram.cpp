class Solution {
public:
    
    bool checkEqual(int arr[26],int arr1[26]){
        for(int i=0;i<26;i++){
            if(arr[i]!=arr1[i]){
                return false;
                }
            }
        return true;
    }
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            arr[index]++;
        }
        int arr1[26]={0};
        for(int i=0;i<t.length();i++){
            int index=t[i]-'a';
            arr1[index]++;
        }
        if(checkEqual(arr,arr1)){
            return true;
        }
        else{
            return false;
        }
    }
};


//approach -2 
class Solution {
public:
    
    
    bool isAnagram(string s, string t) {
        
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            return s==t;
    }
};
