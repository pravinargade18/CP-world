stack<int> _push(int arr[],int n)
{
   stack<int>st;
   int mini=INT_MAX;
   for(int i=0;i<n;i++){
       mini=min(mini,arr[i]);
       st.push(mini);
   }
   return st;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
