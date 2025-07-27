class Solution {
    bool match(string& word, string& s) {
        int n = s.size();
        int m = word.size();
        int i=0;
        int j=0;
        while (i<n and j<m) {
            if (s[i] != word[j]) {
                return false;
            }
            int i1 = i+1;
            while (i1<n and s[i] == s[i1]) {
                i1++;
            }
            int j1 = j+1;
            while (j1<m and word[j] == word[j1]) {
                j1++;
            }
            int lenS = i1-i;
            i = i1;
            int lenW = j1-j;
            j = j1;
            if (lenW > lenS) {
                return false;
            } else if (lenS < 3 and lenS != lenW) {
                return false;
            }
        }
        return (i == n and j == m);
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int n = s.size();
        int ans = 0;
        for (string& word : words) {
            ans += match(word, s);
        }
        return ans;
    }
};