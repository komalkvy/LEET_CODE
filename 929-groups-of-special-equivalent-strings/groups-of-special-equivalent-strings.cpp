class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> seen;
        int maxi = 0;
        for(int i = 0, n = words.size(); i < n; ++i){
            string odd, even;
            for(int j = 0, m = words[i].length(); j < m; ++j){
                if(j & 1) odd.push_back(words[i][j]);
                else even.push_back(words[i][j]);
            }
            sort(odd.begin() , odd.end());
            sort(even.begin() , even.end());
            seen.insert(even + odd);
        }
        return seen.size();
    }
};