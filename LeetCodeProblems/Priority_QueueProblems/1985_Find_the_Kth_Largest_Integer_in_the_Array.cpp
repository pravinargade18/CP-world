class Solution {
public:
    struct comparator
    {
        bool operator () (string& a, string& b)
        {
            if(a.size() == b.size())
                return a > b;
            else
                return a.size() > b.size();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,comparator>pq;
        for(int i=0;i<nums.size();i++){
            
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
