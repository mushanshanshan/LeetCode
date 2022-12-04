class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long> nums;
        
        for (int i=0; i<=sqrt(c); i++) {
            nums.push_back(i*i);
        }
        
        int left = 0, right = nums.size()-1;
        
        while (left<=right) {
            if (nums[left] + nums[right] > c) {
                right--;
            } else if  (nums[left] + nums[right] < c) {
                left++;
            } else if  (nums[left] + nums[right] == c) {
                return true;
            }
        }
        
        return false;
    }
};