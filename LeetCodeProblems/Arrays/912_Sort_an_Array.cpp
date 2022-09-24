


class Solution {
private:
    void merge(vector<int>& nums,int s,int e){
        int mid=s+(e-s)/2;
        int i=s;
        int j=mid+1;
        
        vector<int>v;
        while(i<=mid && j<=e){
            if(nums[i]<nums[j]){
                v.push_back(nums[i]);
                i++;
            }
            else{
                v.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            v.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            v.push_back(nums[j]);
            j++;
        }
         
        int k=0;
        for(int i=s;i<=e;i++){
            nums[i]=v[k++];
        }
        v.clear();
    }
     void mergeSort(vector<int>& nums,int s,int e){
        if(s>=e){
            return ;
        }
        int mid=s+(e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};
