int firstOccurence(vector<int>& arr, int n, int k){
     int s=0;
    int e=n-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<k){
            s=mid+1;
            
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
        return ans;
    }
     int LastOccurence(vector<int>& arr, int n, int k){
     int s=0;
    int e=n-1;
    int ans1=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            ans1=mid;
            s=mid+1;
        }
        else if(arr[mid]<k){
            s=mid+1;
            
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
        return ans1;
    }
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int ,int> p;
    
    int ans=firstOccurence(arr,n,k);
    int ans1=LastOccurence(arr,n,k);
    
    
    p.first=ans;
    p.second=ans1;
    return p;
}
