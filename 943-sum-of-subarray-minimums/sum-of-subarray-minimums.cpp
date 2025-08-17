class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long res = 0;
        long mod = 1e9 + 7;

        stack<int> s1, s2;
        vector<int> prev(n), next(n);

        // Previous Less Element
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i])
                s1.pop();
            prev[i] = s1.empty() ? -1 : s1.top();
            s1.push(i);
        }

        // Next Less Element
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i])
                s2.pop();
            next[i] = s2.empty() ? n : s2.top();
            s2.push(i);
        }

        // Calculate result
        for (int i = 0; i < n; ++i) {
            long left = i - prev[i];
            long right = next[i] - i;
            res = (res + arr[i] * left * right) % mod;
        }

        return res;
    }
};