class Solution {
public:
    int subtractProductAndSum(int n) {
       int product=1;
        int sum=0;
        int digit;
        while(n!=0){
            digit=n%10;
            sum+=digit;
            product*=digit;
            n/=10;
        }
        int ans=product-sum;
        return ans;
    }
};
