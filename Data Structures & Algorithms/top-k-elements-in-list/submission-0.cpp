class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> vec(m.begin(),m.end());

        sort(vec.begin(),vec.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second;
        });

        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};