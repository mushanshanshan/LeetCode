/*
 * @Date: 2022-12-26 14:04:21
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2022-12-26 14:04:27
 * @FilePath: /LeetCode/55. Jump Game 3.cpp
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxIndex=nums[0];

        for (int i=1; i<n; i++) {
            if (i > maxIndex) break;
            maxIndex = max(maxIndex, i + nums[i]);
        }

        return maxIndex >= (n-1);
    }
};