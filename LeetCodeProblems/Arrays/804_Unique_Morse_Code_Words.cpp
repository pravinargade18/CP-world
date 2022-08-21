class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string>s;
        for(int i=0;i<words.size();i++){
            string ele=words[i];
              string str="";
            for(int j=0;j<ele.length();j++){
                int index=ele[j]-'a';
                str.append(arr[index]);
                
            }
            s.insert(str);
        }
        return s.size();
    }
};
