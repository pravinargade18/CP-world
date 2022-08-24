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
    ll arr1[n];
    ll arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    
    ll first=0;
    ll second=0;
    for(int i=0;i<n;i++){
        if(arr1[i]>arr2[i]){
            first+=(arr1[i]-arr2[i]);
        }
         
        else if(arr2[i]>arr1[i]){
            second+=(arr2[i]-arr1[i]);
        }
       
    }
     if(first==second){
            cout<<second<<endl;
        }
    else{
        cout<<-1<<endl;
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
