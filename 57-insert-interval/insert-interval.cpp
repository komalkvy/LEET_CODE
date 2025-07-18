class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        bool inserted = false; 

        // Step 1: Insert the new interval in the correct position
        for(int i = 0; i < n; i++){
            if(newInterval[0] < intervals[i][0]){
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }

        if(!inserted){
            intervals.push_back(newInterval);
        }

        // Step 2: Merge overlapping intervals
        int i = 0;
        while(i < intervals.size() - 1){
            if(intervals[i][1] >= intervals[i + 1][0]){
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + i + 1);
            } else {
                i++;
            }
        }

        return intervals;
    }
};