bool isPossible(vector<int> &arr, int k ,int mid){
    int painter=1;
    int area=0;
    for(int i=0;i<arr.size();i++){
        if(area+arr[i]<=mid){
            area+=arr[i];
        }
        else{
            painter++;
            if(arr[i]>mid || painter>k){
                return false;
            }
            area=arr[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];
    }
    int e=sum;
    int ans=-1;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(isPossible(boards,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
