Time complexity--->O(n2)
Space Complexity --->O(1)


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int arr[7]={12,34,2,45,31,56,27};
    
    for(int i=0;i<6;i++){
        int minIndex=i;
        
        for(int j=i+1;j<7;j++){
            
            if(arr[j]<arr[minIndex])
                minIndex=j;
            
        }
        
        swap(arr[i],arr[minIndex]);
        
    }
    
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}
