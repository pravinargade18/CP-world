vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int ans=0;
    int ans1=0;
    vector<int >v;
    for(int i=0;i<n;i++){
        ans=(ans*10)+a[i];
    }
    for(int i=0;i<m;i++){
        ans1=(ans1*10)+b[i];
    }
    int final =ans+ans1;
    while(final!=0){
        int a=final%10;
        v.insert(v.begin(),a);
        final/=10;
        
    }
    return v;
}
