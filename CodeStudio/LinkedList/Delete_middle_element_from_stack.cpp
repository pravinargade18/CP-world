void solve(stack<int>&inputStack, int count,int size){
    if(size/2==count){
        inputStack.pop();
        return ;
    }
    int num=inputStack.top();
    inputStack.pop();
    solve(inputStack,count+1,size);
    
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	int count=0;
   solve(inputStack,count,N);
   
}
