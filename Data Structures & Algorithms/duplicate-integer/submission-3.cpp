class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) != m.end()) return true;
            else m.insert(nums[i]);
        }
        return false;
    }
};