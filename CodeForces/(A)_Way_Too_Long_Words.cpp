#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    while(n--){
    string s;
    cin>>s;
    if(s.size()>10){
        cout<<s[0]+to_string(s.size()-2)+s[s.size()-1]<<"\n";
    }
    else{
        cout<<s<<"\n";
    }
    }
    return 0;
}
