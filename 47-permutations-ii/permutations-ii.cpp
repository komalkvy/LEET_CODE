class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size() , false);
        sort(nums.begin() , nums.end());
        solve(nums);
        return res;
    }
    void solve(vector<int>& nums){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if( i > 0 && nums[i] == nums[i-1] && !used[ i - 1]) continue ;
            if(!used[i]){
                used[i] = true;
                curr.push_back(nums[i]);
                solve(nums);
                used[i] = false;
                curr.pop_back();
            }
        }
    }
};