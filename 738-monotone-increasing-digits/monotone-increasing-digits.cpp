class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n < 10) return n;

        string s = to_string(n);
        int x = s.size();

        for (int i = 1; i < x; i++) {
            if (s[i - 1] > s[i]) {
                int j = i - 1;
                s[j]--;

                // Fix digits before if they break monotonicity
                while (j >= 1) {
                    if (s[j - 1] > s[j]) {
                        s[j - 1]--;
                        s[j] = '9';
                        j--;
                    } else {
                        break;
                    }
                }

                // Fill the rest with 9s
                while (i < x) {
                    s[i] = '9';
                    i++;
                }

                break;
            }
        }

        return stoi(s);
    }
};