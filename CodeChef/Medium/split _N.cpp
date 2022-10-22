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
    int n;
    cin>>n;
    
    int count=0;
    while(n!=1){
        int j=0;
        while(pow(2,j)<=n){
            j++;
        }
        if(pow(2,j-1)==n){
            break;
        }
        else{
            n=n-pow(2,j-1);
            count++;
        }
    }
    cout<<count<<endl;
    
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
