class Solution {
public:

    void findAllSubsets(int i, vector<vector<int>>& ans, vector<int>& nums, vector<int> subs){
        if(i>=nums.size()){
            ans.push_back(subs);
            return;
        }
        findAllSubsets(i+1, ans, nums, subs);
        subs.push_back(nums[i]);
        findAllSubsets(i+1,ans,nums,subs);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subs;
        findAllSubsets(0, ans, nums, subs);
        return ans;
    }
};
