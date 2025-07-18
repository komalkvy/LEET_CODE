class Solution {
public:
    bool backtracking(int k ,int i,vector<int>& subset,vector<int>&sides,int length){
    int n = subset.size();    
    if(i==n){
        return true;
    }

    for(int j = 0 ; j < k ; j++){
        if(sides[j] + subset[i] <= length){
           sides[j]+=subset[i];
           if(backtracking(k,i+1,subset,sides,length)){
            return true;
           }
           sides[j]-=subset[i];
           if(sides[j]==0)break;
        }
    }
    return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        float length = sum/k;
        vector<int>sides(k,0);

        if(sum/k!=length) return false;

        sort(nums.rbegin(),nums.rend());

        return backtracking(k,0,nums,sides,length);
    }
    
};