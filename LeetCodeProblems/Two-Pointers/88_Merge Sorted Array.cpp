class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 && j>=0){
           if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
               k--;
            }
            else if(nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                j--;
                k--;
                
                
            }
            else{
                nums1[k--]=nums1[i--];
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0){
            nums1[j]=nums2[j];
            j--;
        }
        
        
    }
};


//approach 2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[j++]; //merged all elements of 2nd array into first from m index and then sort the 1st array 
        }
        sort(nums1.begin(),nums1.end());
        
    }
};
