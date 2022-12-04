class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid, count;
        
        while (left < right) {
            count = 0;
            mid  = left + (right - left) / 2;
            for (int& i: nums) {
                if (i <= mid) count++;
            }
            
            if (count > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
            
        }
        
        return left;
    }
};