class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int points[10001] = {0}, take = 0, skip = 0;
        for(int i = 0, n = nums.size(); i < n; ++i) points[nums[i]] += nums[i];
        for(int i = 1; i < 10001; ++i){
            int currtake = skip + points[i];
            int currskip = max(skip , take);
            take = currtake;
            skip = currskip;
        }
        return max(take , skip);
    }
};