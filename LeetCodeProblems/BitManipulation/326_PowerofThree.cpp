class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};


//APPROACH 2
class Solution {
public:
    bool isPowerOfThree(int n) {
        bool ans=false;
        
        for(int i=0;i<=30;i++){
            if(n==pow(3,i)){
                ans=true;
            }
            
            
        }
        return ans; 
    }
};
