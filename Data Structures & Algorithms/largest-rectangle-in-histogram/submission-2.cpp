class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> s;
        int maxi = 0;
        s.push({0,heights[0]});
        for(int i=1;i<n;i++){
            if(!s.empty() && heights[i] < s.top().second){
                int idx=-1,height=-1;
                while(!s.empty() && heights[i] < s.top().second){
                    int area = (i-s.top().first)*(s.top().second);
                    maxi = max(maxi, area);
                    idx = s.top().first;
                    height = s.top().second;
                    s.pop();
                }
                s.push({idx,heights[i]});
            }
            else if(s.empty() || heights[i] >= s.top().second){
                s.push({i,heights[i]});
            }
        }
        while(!s.empty()){
            int area = (n-s.top().first)*(s.top().second);
            maxi = max(maxi, area);
            s.pop();
        }
        return maxi;
    }
};
