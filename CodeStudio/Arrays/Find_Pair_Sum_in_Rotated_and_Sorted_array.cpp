#include<bits/stdc++.h>
int findPairSum(vector<int> arr, int target)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int s=0;
    int e=n-1;
    while(s<e){
        if(arr[s]+arr[e]==target){
            return 1;
        }
        else if(arr[s]+arr[e]<target){
            s++;
        }
        else{
            e--;
        }
    }
    return 0;
    
}
