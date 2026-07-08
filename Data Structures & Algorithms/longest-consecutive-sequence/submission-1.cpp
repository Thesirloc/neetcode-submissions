class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1) != s.end()){
                int temp = nums[i];
                int tempMax = 1;
                while(s.find(temp) != s.end()){
                    tempMax++;
                    temp=temp+1;
                }
                ans = max(ans,tempMax);
            }
        }
        return ans;
    }
};
