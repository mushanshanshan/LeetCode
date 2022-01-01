class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size()-1, mid, row;
        
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            
            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        
        row = left;
    
        
        left = 0, right = matrix[0].size()-1;
        
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            
            if (matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        
        if (matrix[row][left] == target) {
            return true;
        }
        
         return false;
    }
};