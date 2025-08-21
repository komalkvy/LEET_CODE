class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> maxHeap;
        for(auto &rows : matrix) {
            for(auto &ele : rows) {
                maxHeap.push(ele);
                if(maxHeap.size()>k) maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};