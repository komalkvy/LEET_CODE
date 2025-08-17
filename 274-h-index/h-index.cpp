class Solution {
public:
    int hIndex(vector<int>& nums) {
        // Binary search range: 0 to max citation value
        int s = 0, e = INT_MIN;
        for (int num : nums)
            e = max(e, num);

        int ans = 0;
        while (s <= e) {
            int mid = s + (e - s) / 2; // mid is our guess for h-index
            int cnt = 0;

            // Count how many papers have at least mid citations
            for (int num : nums) {
                if (num >= mid) {
                    cnt++;
                }
            }

            // If at least 'mid' papers have ≥ 'mid' citations, move right
            if (cnt >= mid) {
                ans = mid;     // possible answer
                s = mid + 1;   // try bigger h
            }
            // Otherwise, try smaller h
            else {
                e = mid - 1;
            }
        }
        return ans;
    }
};