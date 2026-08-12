class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int ans = 10000;
        int lo = 0, hi = n-1;
        while(lo<=hi){
            if(nums[lo] < nums[hi]){
                ans = min(ans, nums[lo]);
                break;
            }
            int mid = lo + (hi-lo)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[lo]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};
