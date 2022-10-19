#include<bits/stdc++.h>
vector < int > findDuplicates(vector < int > & arr, int n) {
    // Write your code here.
    vector<int>v;
    unordered_map<int,int>m;
    for(auto i:arr){
        m[i]++;
    }
    for(auto i:m){
        if(i.second>=2){
            v.push_back(i.first);
        }
    }
    return v;
   
}
