#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long x,n;
	    cin>>x>>n;
	    if(x==1){
	        cout<<0<<endl;
	    }
	    else{
	        long long ans=(2*n-x)*(x-1);
	        cout<<ans<<endl;
	    }
	    
	    
	}
	return 0;
}
