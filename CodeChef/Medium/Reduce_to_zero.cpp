#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long x,y;
	    cin>>x>>y;
	    if(x==y){
	        cout<<x<<"\n";
	    }
	    else if(x==0 || y==0){
	        cout<<-1<<"\n";
	    }
	    else{
	    if(x>y){
	        swap(x,y);
	    }
	    long long op=0;
	    while(x*2<=y){
	        x*=2;
	        op++;
	    }
	    if(x==y){
	       cout<<y+op<<"\n";
	    }
	    else if(x<y){
	        cout<<y+op+1<<"\n";
	    }
	    }
	    
	    
	}
	return 0;
}
