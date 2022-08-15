#include<bits/stdc++.h>
void solve(string str,int index,vector<string> &s){
    if(index>=str.length()){//if string ends
        s.push_back(str);
        return;
    }
    for(int j=index;j<str.length();j++){ //swap with itself then every next character of the string
        swap(str[index],str[j]);
        solve(str,index+1,s);
        swap(str[index],str[j]);   //backtracking because for next permutation we need the original string
    }
}
vector<string> generatePermutations(string &str)
{
    vector<string>s;
    int index=0;
    solve(str,index,s);
    sort(s.begin(),s.end());  //sorting
    return s;
        
}
