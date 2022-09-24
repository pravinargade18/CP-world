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
