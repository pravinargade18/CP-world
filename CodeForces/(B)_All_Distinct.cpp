#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> s;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            s.insert(temp);
        }
 
        int duplicate = n-s.size();
        if(s.size() < n){
            if(duplicate % 2 == 0){
                cout<<s.size()<<endl;
            }
            else{
                cout<<s.size()-1<<endl;
            }
        }
        else{
            cout<<n<<endl;
        }
        
    }
    
    return 0;
}
