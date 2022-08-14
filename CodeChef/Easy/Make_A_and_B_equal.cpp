#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
    cout.tie(NULL);
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define po pop_back

void solve()
{
    int a,b;
    cin>>a>>b;
    int c,d;
    if(a<b){
        c=a;
        d=b;
    }
    else{
        c=b;
        d=a;
    }
    
    while(c!=d && c<=d){
        c*=2;
    }
    if(c==d){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}


int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
