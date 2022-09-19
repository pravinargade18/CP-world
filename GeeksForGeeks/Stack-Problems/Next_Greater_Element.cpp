class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans;
        stack<long long>st;
        st.push(-1);
        reverse(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && st.top()<=arr[i]){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
