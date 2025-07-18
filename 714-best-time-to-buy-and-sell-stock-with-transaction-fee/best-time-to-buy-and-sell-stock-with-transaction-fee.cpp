class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         vector<int> ahead(2, 0), curr(2, 0);
        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                curr[j] = j ? max(-prices[i]-fee + ahead[0], ahead[1])
                            : max(prices[i] + ahead[1], ahead[0]);
            }
            ahead = curr;
        }
        return curr[1];
    }
};