class Solution {
public:
    int findMin(vector<int>& arr) {
    int s=0;
    int e=arr.size()-1;
    int mid=0;
    while(s<e){
        mid=s+(e-s)/2;
        if(arr[mid]>arr[e]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return arr[s];

    }
};
