class Solution {
public:
    struct node {
        int data, row, column;
        node(int value, int i, int j) : data(value), row(i), column(j) {}
    };
    struct comparator {
        bool operator() (node a, node b) {
            return a.data > b.data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        priority_queue<node, vector<node>, comparator> minHeap;
        int currMin = INT_MAX, currMax = INT_MIN, currRange = INT_MAX;
        
        for(int i = 0; i < k; ++i) {
            currMax = max(currMax, nums[i][0]);
            node temp(nums[i][0], i, 0);
            minHeap.push(temp);
        }
        
        int start = currMin, end = currMax;
        while(true) {
            node min = minHeap.top();
            minHeap.pop();
            currMin = min.data;
            
            if(currMax - currMin < currRange) {
                start = currMin;
                end = currMax;
                currRange = currMax - currMin;
            }
            
            if(min.column + 1 == nums[min.row].size())
                break;
            node next(nums[min.row][min.column + 1], min.row, min.column + 1);
            minHeap.push(next);
            
            if(next.data > currMax)
                currMax = next.data;
        }
        return {start, end};
    }
};
