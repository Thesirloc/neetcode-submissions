class Solution {
public:

    void uniqueCombinations(int i, vector<vector<int>>& ans, vector<int>& nums, vector<int>& comb, int sum, int target){
        if(sum == target){
            ans.push_back(comb);
            return;
        }
        if(i>=nums.size() || sum>target) return;
        uniqueCombinations(i+1, ans, nums, comb, sum, target);
        comb.push_back(nums[i]);
        uniqueCombinations(i, ans, nums, comb, sum + nums[i], target);
        comb.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        uniqueCombinations(0, ans, nums, comb, 0, target);
        return ans;
    }
};