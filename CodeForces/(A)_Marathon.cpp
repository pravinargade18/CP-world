#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        int cnt=0;
        for(int i=0;i<4-1;i++){
            if(a<v[i+1]){
                cnt++;
            }
           
        }
        cout<<cnt<<"\n";
        
    }
 
    return 0;
}
