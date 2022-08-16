#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        string s2;
        cin>>s2;
        string s1="YES";
        transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
        if(s1==s2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
