// function to find pivot...
int findPivot(vector<int>& arr,int n){
        int s=0;
        int e=n-1;
        int mid;
        while(s<e){
            mid=s+(e-s)/2;
            if(arr[mid]>=arr[0]){ //this means element lies on first line or in first part but we have to check in second part so s=s+1
                s=mid+1;
            }
            else{                    // element lies on second part which starts from value less than arr[0] & we will take e=mid because element can be mid element itself .
                e=mid;
            }
        }
    return s;
//     return e;
}

// binary search function to search given element
int binarySearch(vector<int>& arr,int s,int e,int k){
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(k==arr[mid]){
            return mid;
        }
        else if(k<arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{
//    we have two parts in first part all the elements greater than arr[0] are present and in second part elements less than arr[0] are present and we have to search for an element so we have to decide the search space and we will get it after finding pivot element which is on second line first position and we also have end point so we can check if element lies in between pivot and last ele if yes then search in second part else in first part.
    int pivot=findPivot(arr,n);
    int ans=-1;
    if(k>=arr[pivot] && k<=arr[n-1]){  //element lies in second line or second part
        ans=binarySearch(arr,pivot,n-1,k);
    }
    else{  //element lies in first part
        ans=binarySearch(arr,0,pivot-1,k);
    }
    return ans;
}

