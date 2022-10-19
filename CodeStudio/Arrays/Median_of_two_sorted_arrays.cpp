#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    int a_size=a.size();
    int b_size=b.size();
    vector<int>v;
    for(int i=0;i<a_size;i++){
       v.push_back(a[i]);
    }
    for(int i=0;i<b_size;i++){
       v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    if(v.size()%2==0){
        double a=v[v.size()/2];
        double b=v[(v.size()/2)-1];
        double ans=(a+b)/2;
        return ans;
    }
    else{
        double a=v[v.size()/2];
        return a;
    }
}
