#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top()>=arr[i]){
            st.pop();
        }
        ans.push_back(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
