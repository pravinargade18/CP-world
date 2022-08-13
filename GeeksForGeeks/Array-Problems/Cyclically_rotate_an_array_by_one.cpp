void rotate(int arr[], int n)
{ 
    int temp[n];
    for(int i=0;i<n;i++){
        temp[(i+1)%n]=arr[i];
    }
    copy(temp, temp+n, arr); 
}
