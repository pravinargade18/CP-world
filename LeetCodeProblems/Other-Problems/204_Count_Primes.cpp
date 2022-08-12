class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        vector<bool>prime(n+1,true);  //all the numbers including 0 marked as true first 
        // prime[0]=prime[1]=false;   make first two indexes number as false i.e.0 and 1
        for(int i=2;i<n;i++){
            if(prime[i]){
                cnt++;
                for(int j=i+i;j<n;j=j+i){
                    prime[j]=false;
                }
            }
        }
        return cnt;
            
}
    
};
