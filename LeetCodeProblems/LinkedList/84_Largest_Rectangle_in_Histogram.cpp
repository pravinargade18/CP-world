class Solution {
private:
    vector<int>nextSmallerElement(vector<int>& arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int>prevSmallerElement(vector<int>& arr,int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int length=heights[i];
           
            if(next[i]==-1){
                next[i]=n;
            }
             int breadth=next[i]-prev[i]-1;
            int newArea=length*breadth;
            area=max(area,newArea);
        }
        return area;
    }
};
