/*
 * @Date: 2022-12-27 15:24:23
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2022-12-27 15:24:27
 * @FilePath: /LeetCode/2279. Maximum Bags With Full Capacity of Rocks.cpp
 */
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size(), res = 0;

        for (int i=0; i<n; i++) {
            capacity[i] -= rocks[i];
        }

        sort(capacity.begin(), capacity.end());

        for (int i=0; i<n; i++) {
            if (additionalRocks >= capacity[i]) {
                res++;
                additionalRocks -= capacity[i];
            } else break;
        }

        return res;
    }
};