class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        unordered_map<int, int> mpp;

        for (int x : arr) mpp[x]++;

        long res = 0;
        for (auto it1 : mpp) {
            for (auto it2 : mpp) {
                int i = it1.first, j = it2.first;
                int k = target - i - j;
                if (!mpp.count(k)) continue;

                // i == j == k
                if (i == j && j == k) {
                    res += 1L * mpp[i] * (mpp[i] - 1) * (mpp[i] - 2) / 6;
                }
                // i == j != k
                else if (i == j && j != k) {
                    res += 1L * mpp[i] * (mpp[i] - 1) / 2 * mpp[k];
                }
                // i < j < k (avoid duplicates)
                else if (i < j && j < k) {
                    res += 1L * mpp[i] * mpp[j] * mpp[k];
                }
            }
        }
        return res % mod;
    }
};