// Approach 1-->using recursion
void reverseQueue(queue<int> &q){
    if(q.empty()){
        return;
    }
    int ele=q.front();
    q.pop();
    reverseQueue(q);
    q.push(ele);
}
queue<int> rev(queue<int> q)
{
    
    reverseQueue(q);
    return q;
}



// Approach 2-->using stack

queue<int> rev(queue<int> q)
{
    stack<int>st;
    while(!q.empty()){
        int val=q.front();
        st.push(val);
        q.pop();
    }
    while(!st.empty()){
        int val=st.top();
        q.push(val);
        st.pop();
    }
    return q;
}
