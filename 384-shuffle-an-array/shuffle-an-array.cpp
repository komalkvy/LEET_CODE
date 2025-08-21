vector<int> v;
int n ;
class Solution {
public:
    Solution(vector<int>& nums) {
      v=nums;  
      n=nums.size();
    }
    
    vector<int> reset() {
        return v;   
    }
    
    vector<int> shuffle() {
        vector<int> ans=v;

// way 1
    random_shuffle(ans.begin(), ans.end());

// way 2
    // next_permutation(ans.begin(), ans.end());

// way 3
//  for(int i = n - 1; i >= 0; --i){
//             int j = rand() % (i + 1);
//             swap(dup[i] , dup[j]);
        // }
        
    return ans;
    }
};