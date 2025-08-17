class Solution {
public:
#include<unordered_map>
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res;
        unordered_map< int, int> freq;

        for(int i = 0; i < n; i++)
            freq[nums[i]] ++;

        for(int i = 0; i < n; i++){

            if(freq[nums[i]] > n/ 3){
                
                res.push_back(nums[i]);
                freq.erase(nums[i]);
            }
        }

        return res;
    }
};