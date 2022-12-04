class Solution {
public:
    bool canSplit(vector<int>& nums, int n, int ns) {
        long cnt = 1, s = 0;
        
        for (int & i: nums) {
            s += i;
            if (s > ns) {
                cnt++;
                s = i;
                if (cnt > n) return false;
            }
        }
        return true;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;
        for (int & i: nums) {
            left = max(left, (long)i);
            right += i;
        }
        
        if (m == 1) return right;
        if (m == nums.size()) return left;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canSplit(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        
        return right;
    }
};