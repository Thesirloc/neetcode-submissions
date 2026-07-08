class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it: m){
            buckets[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i=n;i>=1;i--){
            for(int j=0;j<buckets[i].size();j++){
                ans.push_back(buckets[i][j]);
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};