
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right){
        int count = 0, leftIndex = -1, lastValidIndex = -1;
        // lastvalidexIndex means the end 
        int n = nums.size();
        for (int i = 0; i <n;i++){
            if (nums[i] > right){
                leftIndex = i; 
            }
            if(nums[i] >= left && nums[i] <= right){
                lastValidIndex = i;
            }
            if(lastValidIndex > leftIndex){
                count += (lastValidIndex - leftIndex);
            }
        }
        return count;
        /* 


Dry Run with Example [2, 9, 2, 5, 6]:
Initialization: count = 0, leftIndex = -1, lastValidIndex = -1.

i = 0 (nums[0] = 2)

nums[0] is within [left, right] → lastValidIndex = 0.

count += (lastValidIndex - leftIndex) = 0 + (0 - (-1)) = 1.

i = 1 (nums[1] = 9)

nums[1] is greater than right → leftIndex = 1.

lastValidIndex is not updated as nums[1] is out of range.

i = 2 (nums[2] = 2)

nums[2] is within [left, right] → lastValidIndex = 2.

count += (lastValidIndex - leftIndex) = 1 + (2 - 1) = 2.

i = 3 (nums[3] = 5)

nums[3] is within [left, right] → lastValidIndex = 3.

count += (lastValidIndex - leftIndex) = 2 + (3 - 1) = 4.

i = 4 (nums[4] = 6)

nums[4] is within [left, right] → lastValidIndex = 4.

count += (lastValidIndex - leftIndex) = 4 + (4 - 1) = 7.
*/
    }
};