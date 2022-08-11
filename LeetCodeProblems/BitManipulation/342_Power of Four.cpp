class Solution {
public:
    bool isPowerOfFour(int n) {
      for(int i=0;i<=30;i++){
          if(pow(4,i)==n){
              return true;
          }
      }
        return false;
    }
};


//APPROACH 2
class Solution {
public:
    bool isPowerOfFour(int n) {
    if(n>0){
    int setBits= __builtin_popcount(n);
    int zeroCount=__builtin_ctz(n);     //if setbit is 1 and no of trailing zeroes are even then the number is pow of 4
    if(setBits==1 && zeroCount%2==0){
        return true;
    }
    }
    return false;
    }
};
