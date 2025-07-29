class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), maxDist = 0;
        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i]) {
                if (prev == -1) maxDist = i;
                else maxDist = max(maxDist, (i - prev) / 2);
                prev = i;
            }
        }
        maxDist = max(maxDist, n - 1 - prev);
        return maxDist;
    }
};