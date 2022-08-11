//APPROACH 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n<=0?false:(n&(n-1))==0;
    }
};



//APPROACH 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool ans=false;
        for(int i=0;i<31;i++){
            if(pow(2,i)==n){
                ans= true;
            }
        }
        return ans;
    }
};
