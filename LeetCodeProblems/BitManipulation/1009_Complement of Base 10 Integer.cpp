class Solution {
public:
    int bitwiseComplement(int n) {
        int i=0;
        int power=1;
        int ans=0;
        if(n==0){
            return 1;
        }
        while(n!=0){
            int bit=n&1;  //to get the last bit
            if(bit==0){  //bit =0 means actually it is 1 after complementing
                ans+=power; //means if bit is 1 we will multiplying  by updated power of 2
            }
            n>>=1;
            power*=2;   //increasing power everytime because each bit is in pow of 2
        }
        return ans;
        }
    
    
};
