class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        vector<int>v;
        int i=0;
        d=d%n;
        for(i=0;i<d;i++){
            v.push_back(arr[i]);
        }
        for( i=0;i<n-d;i++){
            arr[i]=arr[i+d];
        }
        int k=0;
        while(i<n){
            arr[i++]=v[k++];
        }
    }
};
