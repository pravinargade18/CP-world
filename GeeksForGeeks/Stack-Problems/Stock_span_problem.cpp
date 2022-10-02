
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector <int>ans;
       stack<int>st;
       for(int i=0;i<n;i++){
           while(!st.empty() && price[st.top()]<=price[i]){
               st.pop();
           }
           if(st.empty()){
               ans.push_back(i + 1);
           }
           else{
               ans.push_back(i-st.top());
           }
           st.push(i);
       }
       return ans;
    }
};
