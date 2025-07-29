class Solution {
public:
    template<typename Bidirectional_iterator>
    void reverse(Bidirectional_iterator first , Bidirectional_iterator last)
    {
        while(first!=last && first!=--last)
        {
            iter_swap(first, last);
            first++;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == 1) return;
        k = k % n;

        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};