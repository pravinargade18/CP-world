#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<"\n";
        }
        else{
            if(a>b){
                swap(a,b);
            }
            int op=0,div=0,mod=0,sub=0;
            sub=b-a;
            div=sub/10;
            mod=sub%10;
            op=div;
            if(mod>0){
                op++;
            }
            cout<<op<<"\n";
        }
    }
    return 0;
}
