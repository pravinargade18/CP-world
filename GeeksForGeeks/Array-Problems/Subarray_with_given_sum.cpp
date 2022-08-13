class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int>v;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum>s){
                    break;
                }
                if(sum==s){
                    v.push_back(i+1);
                    v.push_back(j+1);
                    return v;
                }
                
                
            }
        }
        v.push_back(-1);
        return v;
    }
};
