class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int sol = 0, n = arr.size();
        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int idx1 = i, idx2 = i;
                int left = 0, right = 0;
                while (idx1 > 0 && arr[idx1 - 1] < arr[idx1]) {
                    left++;
                    idx1--;
                }
                while (idx2 < n - 1 && arr[idx2] > arr[idx2 + 1]) {
                    right++;
                    idx2++;
                }
                sol = max(left + right + 1, sol);
            }
        }
        return sol;
    }
};