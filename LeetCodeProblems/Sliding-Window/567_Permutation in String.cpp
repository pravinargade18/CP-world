class Solution {
public:
    
    bool checkEqual(int count1[26],int count2[26]){
        for(int i=0;i<26;i++){
            if(count1[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
    
    bool checkInclusion(string s1, string s2) {
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;
            // store the count of the each character at array indexes where a=0 index of string s1
        }
        
        int i=0;
        int windowSize=s1.length();
        //create a window of the size of string s1
        int count2[26]={0};
        while(i<windowSize && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
            // create the same array of character count for that window characters 
        }
        if(checkEqual(count1,count2)){
            return true;
            // if the count of the characters are same then the anyone permutation of the string s1 will be in s2
        }
        
        while(i<s2.length()){
            // for every window we have to add next character and increase its count and delete the count of the previous character 
            int newChar=s2[i];
            int index=newChar-'a';
            count2[index]++;
            
            int oldChar=s2[i-windowSize];
            index=oldChar-'a';
            count2[index]--;
            
            i++;
            
            // again compare the two array using function checkEqual
            if(checkEqual(count1,count2)){
                return true;
            }
        }
        
        return false;
        
    }
};
