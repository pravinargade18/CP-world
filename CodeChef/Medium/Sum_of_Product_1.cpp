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
    int a[n];
    long long cnt=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i]; 
    }
    for(int i=0;i<n;i++){
       
           if(a[i]==1){
                cnt++;
             }
        else{
            ans+=(cnt*(cnt+1)/2);
            cnt=0;
                 
            }
        }
       ans+=(cnt*(cnt+1)/2); 
    
    
    cout<<ans<<endl;
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
