class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt_violations = 0;

        for ( int i=1; i < nums.size(); i++ ) {
            if ( nums[i-1] > nums[i] ) {
                cnt_violations++;
                if ( cnt_violations > 1 ) return false;

                // only when 130 pattern, shall you increase nums[i]
                if ( i-2 >= 0 && nums[i-2] > nums[i] ) {
                    nums[i] = nums[i-1];
                }
                // 132 pattern -> decrease nums[i-1]
                else {
                    nums[i-1] = nums[i];
                }
            }
        }
        return true;
    }
};