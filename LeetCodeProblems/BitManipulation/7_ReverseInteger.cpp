class Solution {
public:
    int reverse(int x) {
       int ans=0;
       while(x!=0){
           int digit=x%10;       //to get the last digit 
          
           if((ans>INT_MAX/10) || (ans<INT_MIN/10)){  //if ans goes out of int range.we will divide Max and Min values by 10 to get ans in range 
               return 0;
           }              
           
           ans=(ans*10)+digit;  //to get the digits combined
           x/=10;               //to remove digit
       }
       return ans;
    }
};
