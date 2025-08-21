class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int l = 0, n = nums.size(), count = 0, existingdiff = 0;
        for (int r = 1; r < n; r++) {
            int currentdiff = nums[r] - nums[r - 1];
            if (currentdiff == existingdiff) {
                if (r - l + 1 == 3) {
                    count++;
                }else if(r - l + 1 > 3){
                    count+=r-l+1-2;
                }
            } else {
                existingdiff = currentdiff;
                l = r - 1;
            }
        }
        return count;
    }
};