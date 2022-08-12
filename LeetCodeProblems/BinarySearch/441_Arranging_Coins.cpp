class Solution {
public:
    int arrangeCoins(int n) {
     int s=0;
    int e=n;
        long long mid;
        while(s<=e){
            mid=s+(e-s)/2;
            long long temp=mid*(mid+1)/2;
            
            if(temp<=n){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s-1;
    }
};
