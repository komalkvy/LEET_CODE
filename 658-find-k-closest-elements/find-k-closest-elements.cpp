class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Better approach 
        int i = 0;
        int n = arr.size();
        // find the highest element index lesser than x
        while(i < n && arr[i] < x) i++;
        int left = i-1, right = i;
       // if(arr[right] == x) right ++;
        vector<int>ans;
        while(left >= 0 && right < n && ans.size() < k){
            int difA = abs( x - arr[left]);
            int difB = abs(x - arr[right]);
            if(difA <= difB){
                ans.push_back(arr[left]);
                left--;
            }else{
                ans.push_back(arr[right]);
                right ++;
            }
        }
        while(left >= 0 && ans.size() < k){
           ans.push_back(arr[left]);
                left--;
        }
        while(right < n && ans.size() < k){
           ans.push_back(arr[right]);
                right++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};