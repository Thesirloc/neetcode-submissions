class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = 0;
        for(int i=0;i<n;i++){
            maxPile = max(maxPile, piles[i]);
        }
        int lo = 1,hi=maxPile;
        int ans = hi;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int t = 0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid == 0) t += piles[i]/mid;
                else t += (piles[i]/mid + 1);
            }
            if(t <= h){
                ans = min(mid, ans);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
