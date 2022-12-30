/*
 * @Date: 2022-12-28 16:20:28
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2022-12-28 16:20:34
 * @FilePath: /LeetCode/1962. Remove Stones to Minimize the Total.cpp
 */
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        vector<int> count(10001, 0);

        for (int i: piles) count[i]++;

        int max = 10000, time = 0;

        while (time < k) {
            while (count[max] == 0) max--;

            time++;
            count[max]--;
            count[max - (int)floor(max/2)]++;
        }

        int res = 0;
        for (int i=0;i<10001; i++) res += i*count[i];

        return res;
    }
};