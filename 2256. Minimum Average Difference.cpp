class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int minIndex = 0, minDiff = INT_MAX, n = nums.size();

        if (nums.size() == 1) return 0;

        long long left = 0, right = 0;

        for (int i: nums) right += i;

        for (int i=0; i<n; i++) {
            left += nums[i];
            right -= nums[i];
            long leftAvg = round(left / (i + 1));
            long rightAvg = i==(n-1) ? 0: round(right / (n - 1 - i));
            long diff = abs(leftAvg - rightAvg);
            if (diff < minDiff) {
                minDiff = diff;
                minIndex = i;
            }
        }

        return minIndex;




    }
};