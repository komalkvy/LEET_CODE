class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        
        // Number of Elements
        int N  = nums.size();
      
        // Sort so that we can have partition
        sort(nums.begin(), nums.end());

        // Trivial Case, all incremented OR all decremented
        int score = nums[N-1] - nums[0];

        // To store minimum score
        int ans   = score;

        // Check all N-1 Non-Trivial partitions/walls. 
        // Both sets will be non-empty   
        for (int divider = 0; divider < N-1; divider++){

            // Compute maximum and minimum after partitioning
            // Kudos! We only have two candidates for each
            int maximumAfterDivision = max(nums[divider]    + k , nums[N-1] - k);
            int minimumAfterDivision = min(nums[divider+1]  - k , nums[0]  + k);

            // Score after dividing here
            score = maximumAfterDivision - minimumAfterDivision;

            // ans will be minimum score
            ans = min(ans, score);
        }
        
        // return answer
        return ans;
    }
};