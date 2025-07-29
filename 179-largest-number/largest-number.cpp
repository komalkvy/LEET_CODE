class Solution {
public:
    static bool compare(string& a, string& b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums)
            strNums.push_back(to_string(num));

        sort(strNums.begin(), strNums.end(), compare);

        if (strNums[0] == "0") return "0"; // Edge case: all zeros

        string result;
        for (string& s : strNums)
            result += s;

        return result;
    }
};