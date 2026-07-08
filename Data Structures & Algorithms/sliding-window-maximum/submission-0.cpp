class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int currMax = -99999999;
        int n = nums.size();
        multiset<int> s;
        for(int i=0;i<k;i++){
            s.insert(nums[i]);
        }
        vector<int> ans;
        int maxi = *s.rbegin();
        ans.push_back(maxi);
        int i=0,j=k;
        while(j<n){
            if(!s.empty()){
                auto it = s.find(nums[i]);
                if(it != s.end()){
                    s.erase(it);
                }
                s.insert(nums[j]);
                maxi = *s.rbegin();
                ans.push_back(maxi);
                j++;
                i++;
            }
        }
        return ans;
    }
};
