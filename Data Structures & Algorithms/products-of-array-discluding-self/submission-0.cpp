class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        double product = 1;
        for(int i=0;i<nums.size();i++){
            product = product*nums[i];
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0) ans.push_back(product/nums[i]);
            else {
                double prod = 1;
                for(int j=0;j<nums.size();j++){
                    if(j != i) prod = prod*nums[j];
                }
                ans.push_back(prod);
            }
        }
        return ans;
    }
};
