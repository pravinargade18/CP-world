class Solution {
public:
    int fib(int n) {
        //base case
        if(n==0){
            return 0;
        }
        //base case
        if(n==1){
            return 1;
        }
        int ans=fib(n-1)+fib(n-2);
        return ans;
    }
};


//approach 2 using dynamic programming

class Solution {
public:
 int dp[31];
int calculate(int n)
{
    if(n==0||n==1){
         return dp[n]=n;
     }
    if(dp[n]!=-1)
        return dp[n];
    
    return calculate(n-1)+calculate(n-2);
    
}
int fib(int n) 
{
     memset(dp,-1,sizeof(dp));
    int ans=calculate(n);
    return ans;
   
}
};
