class Solution {
public:

    int binarysearch(vector<int> &nums, int target){
        int l = 0, r = nums.size();
        int m = 0;
        while(l < r){
            m = l+(r-l)/2;
            if(nums[m] <= target) l = m+1;
            else r = m;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0 || target > nums[nums.size()-1] || target < nums[0]) return {-1,-1};
        vector<int> res = {binarysearch(nums, target-1), binarysearch(nums, target)-1};
        if(nums[res[0]] != nums[res[1]] || nums[res[0]] != target || nums[res[1]] != target) return {-1,-1};
        return res;
    }
};