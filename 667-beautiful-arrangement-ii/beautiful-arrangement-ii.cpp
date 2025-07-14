class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);

        int left = 1, right = n;

        // 1,2,3... 
        for ( int i=0; i < (n-k); i++ ) {
            res[i] = left++;
        }

        // maximum element at (n-k)th index
        res[n-k] = right--;

        bool add_left = true;
        
        // for index b/w [n-k+1,n) -> alternate b/w min and max
        for ( int i=n-k+1; i < n; i++ ) {
            res[i] = (add_left) ? left++ : right--;
            add_left = !add_left;
        }

        return res;
    }
};