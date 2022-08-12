class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> v; 
       for(int i=0;i<m;i++){
           v.push_back(nums1[i]);
       }
         for(int i=0;i<n;i++){
           v.push_back(nums2[i]);
       }
        sort(v.begin(),v.end());
          if(v.size()%2==0){
            
           double a=v[((m+n)/2)-1];
           double b=v[((m+n)/2)];
           double ans=(a+b)/2;
            return ans;
        }
        else{
            double ans=(v[floor(v.size()/2)]);
            return ans;
        }

    }
};
