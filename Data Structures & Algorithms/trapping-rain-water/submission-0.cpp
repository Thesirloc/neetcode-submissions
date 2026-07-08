class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int watersum = 0;
        vector<int>prefix;
        prefix.push_back(0);
        for(int i=1;i<n;i++){
            prefix.push_back(max(prefix[i-1], height[i-1]));
        }
        vector<int>suffix(n,0);
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1], height[i+1]);
        }
        for(int i=0;i<n;i++){
            int waterati = min(prefix[i],suffix[i]) - height[i];
            if(min(prefix[i],suffix[i]) - height[i] >0){
                watersum += waterati;
            }
        }
        return watersum;
    }
};
