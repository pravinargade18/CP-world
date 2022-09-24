// Approach 1
class Solution {
private:
    void merge(vector<int>& nums,int s,int e){
        int mid=s+(e-s)/2;
        int len1=mid-s+1;
        int len2=e-mid;
        
        int *first=new int[len1];
        int *second=new int[len2];
        
        
        int k=s;
        for(int i=0;i<len1;i++){
            first[i]=nums[k++];
        }
        k=mid+1;
        for(int i=0;i<len2;i++){
            second[i]=nums[k++];
        }
        int index1=0,index2=0;
        k=s;
        while(index1<len1 && index2< len2){
            if(first[index1]<second[index2]){
                nums[k++]=first[index1++];
            }
            else{
               nums[k++]=second[index2++]; 
            }
        }
        while(index1<len1){
            nums[k++]=first[index1++];
        }
        while(index2<len2){
            nums[k++]=second[index2++];
        }
        delete [] first;
        delete []  second;
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


    

// Approach 2-->another merging approach
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
