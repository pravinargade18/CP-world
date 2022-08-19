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
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll mini_gcd=arr[0];
    for(int i=1;i<n;i++){
        mini_gcd=__gcd(mini_gcd, arr[i]);
    }
    cout<<mini_gcd*n<<endl;
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
