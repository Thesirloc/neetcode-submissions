class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int n = heights.size();
        int j = n-1;
        int maxWater = 0;
        while(i<j){
        maxWater = max(maxWater, (j-i)*min(heights[i],heights[j]));
        heights[i] < heights[j] ? i++ : j--;
        }
        return maxWater;
    }
};
