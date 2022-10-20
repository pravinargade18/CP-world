#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a;
        vector<int> v;
        int cnt=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if(a%2!=0){
                cnt++;
            }
            v.push_back(a);
            
           
        }
         sort(v.begin(), v.end());
         a=v.front();
         if(a==1){
             cout<<"CHEF"<<"\n";
         }
         else if(cnt%2==0){
             cout<<"CHEFINA"<<"\n";
         }
        else{
            cout<<"CHEF"<<"\n";
      }
       
        
    }
    return 0;
}
