class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> dict(words.begin(), words.end());
        for (const string& word : words) {
            if(!dict.count(word)) continue;
            for (int i = 1; i < word.length(); ++i) dict.erase(word.substr(i));
        }
        int total = 0;
        for (const string& w : dict) total += w.length() + 1;
        return total;
    }
};