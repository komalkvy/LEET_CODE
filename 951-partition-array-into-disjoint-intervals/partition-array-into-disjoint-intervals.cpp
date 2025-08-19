class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxLeft = nums[0], currMax = nums[0], idx = 0;
        for (int i = 1, n = nums.size(); i < n; ++i) {
            currMax = max(currMax, nums[i]);
            if (nums[i] < maxLeft) {
                maxLeft = currMax;
                idx = i;
            }
        }
        return idx + 1;
    }
};