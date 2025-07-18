class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        // Treat the matrix as a flattened sorted 1D array
        int start = 0;
        int end = row * col - 1;

        while (start <= end) {
            // Find mid index of the virtual 1D array
            int mid = start + (end - start) / 2;

            // Convert 1D index to 2D coordinates
            int element = matrix[mid / col][mid % col];

            if (element == target) {
                // Found the target
                return true;
            } else if (element < target) {
                // Target is in the right half
                start = mid + 1;
            } else {
                // Target is in the left half
                end = mid - 1;
            }
        }

        // Target not found
        return false;
    }
};