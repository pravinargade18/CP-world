class Solution {
private:
   void solve(string digits,int index,string output,string mapping[],vector<string>&ans){
        if(index>=digits.length()){
            ans.push_back(output);   //if we reaches to the end of the number push_back the output string into main ans
            return;
        }
        
        int number=digits[index]-'0';   //by digits[index] we will get character single character of number convert it into int value by subtracting ascii value of '0';
        string value=mapping[number];   //value mapped with that number in array mapping
        
        //now we will take single single character from the value
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,index+1,output,mapping,ans);
            output.pop_back();      //backtracking to remove previous character
        }
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        //edge case if digits is empty string
        if(digits.length()==0){
            return ans;    //return empty vector
        }
        string output="";
        int index=0;
        //mapping values with number buttonwise
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,output,mapping,ans);
        return ans;
    }
};
