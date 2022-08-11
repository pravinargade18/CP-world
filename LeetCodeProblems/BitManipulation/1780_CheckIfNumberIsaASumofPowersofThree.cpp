class Solution {
public:
    bool checkPowersOfThree(int n) {
        bool ans=true;
        while(n>0){
            if(n%3==2){
                ans=false;
            }
            n/=3;
        }
        
        return ans;
    }
};
