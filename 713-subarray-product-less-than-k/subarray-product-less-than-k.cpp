class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0; // Edge case
        int count = 0;
        int prod = 1, start = 0;
        for(int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while(prod >= k) {
                prod /= nums[start++];
            }
            count += right - start + 1;
        }
        return count;
    }
};