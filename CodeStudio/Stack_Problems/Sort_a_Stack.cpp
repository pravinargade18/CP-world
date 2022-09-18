void insertAtCorrectPos(stack<int> &s,int ele){
    if(s.empty() || s.top()<ele){
        s.push(ele);
        return;
    }
    int num=s.top();
    s.pop();
    insertAtCorrectPos(s,ele);
    s.push(num);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();
    sortStack(stack);
    insertAtCorrectPos(stack,num);
}
