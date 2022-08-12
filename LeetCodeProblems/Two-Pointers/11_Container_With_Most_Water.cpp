class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1;
        int i=0;
        int maxArea=0;
        while(i<j){
            int mini=min(height[i],height[j]);
            int water=((j-i)*mini);
            maxArea=max(maxArea,water);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};
