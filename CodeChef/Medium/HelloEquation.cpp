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
    cin>>x;             //a*(2+b)+2b=x   ...a=(x-2b)/(2+b)  if this is perfect division then a will exist for sure
    int a=0;                    
    for(int b=1;b<=sqrt(x);b++){
        if((x-2*b)%(2+b)==0 && 2*b!=x){   //and also 2b should not be x otherwise a will be 0 but we need a>0 so this condition
            a++;
            break;     
        }
    }
    if(a>0){               //if we got such a then obiviously a>0 so print yes
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
