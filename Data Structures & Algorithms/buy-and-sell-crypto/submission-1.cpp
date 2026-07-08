class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<1) return 0;
        int maxProfit = 0;
        int currMax = prices[n-1];
        for(int i=n-2;i>=0;i--){
            int profit = currMax - prices[i];
            if(profit > 0){
                maxProfit = max(maxProfit, profit);
            }
            currMax = max(currMax, prices[i]);
        }
        return maxProfit;
    }
};
