class Solution {
private:
    int sumOfdigits(int n){
        int sum=0;
        while(n!=0){
            int digit=n%10;
            sum+=(digit*digit);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        while(n!=1 && n!=4){
             n=sumOfdigits(n);
        }
        if(n==1){
            return true;
        }
        else{
            return false;
        }
        
        
        
    }
};
