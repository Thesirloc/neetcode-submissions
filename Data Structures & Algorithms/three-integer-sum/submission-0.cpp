class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return {};
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int currsum = nums[j]+nums[k]+nums[i];
                if(currsum==0){
                    vector<int> temp = {nums[j],nums[k],nums[i]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                    int small = nums[j];
                    while(nums[j] == small) j++;
                    int big = nums[k];
                    while(nums[k] == big) k--;
                }
                else if (currsum > 0){
                    int big = nums[k];
                    while(nums[k] == big) k--;
                }
                else{
                    int small = nums[j];
                    while(nums[j] == small) j++;
                }
            }
        }
        vector<vector<int>> finalAns;
        for(auto it: ans){
            finalAns.push_back(it);
        }
        return finalAns;
    }
};
