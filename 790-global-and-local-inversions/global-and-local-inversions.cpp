class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i){
                continue;
            }
            else if(nums[i]-1==i or nums[i]+1==i)
                continue;
            else
                return false;
        }
        return true;
    }
};