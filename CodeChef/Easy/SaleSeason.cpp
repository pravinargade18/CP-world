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
    int x;
    cin>>x;
    if(x>100 && x<=1000){
        cout<<x-25<<endl;
    }
    else if(x>1000 && x<=5000){
        cout<<x-100<<endl;
    }
    else if(x>5000){
        cout<<x-500<<endl;
    }
    else{
        cout<<x<<endl;
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
