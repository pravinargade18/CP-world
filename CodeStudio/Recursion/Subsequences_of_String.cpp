void solve(string str,int index,string s,vector<string>&ans){
    if(index>=str.length()){
        if(s.length()>0){
        ans.push_back(s);
     
        }
           return;
    }
    solve(str,index+1,s,ans);
    s.push_back(str[index]);
    solve(str,index+1,s,ans);
}

vector<string> subsequences(string str){
	
	// Write your code here
    vector<string>ans;
    string s="";
    solve(str,0,s,ans);
    return ans;
	
}
