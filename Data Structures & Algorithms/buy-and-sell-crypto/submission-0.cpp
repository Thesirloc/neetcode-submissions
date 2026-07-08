class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lowestYet = prices[0];
        int maxProfit = 0;
        for(int i=1;i<n;i++){
            maxProfit = max(prices[i]-lowestYet, maxProfit);
            lowestYet = min(lowestYet, prices[i]);
        }
        return maxProfit;
    }
};
