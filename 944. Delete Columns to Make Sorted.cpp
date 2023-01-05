/*
 * @Date: 2023-01-03 14:06:32
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2023-01-03 14:06:47
 * @FilePath: /LeetCode/944. Delete Columns to Make Sorted.cpp
 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        int N = strs[0].size(), M = strs.size();

        for (int c=0; c<N; c++) {
            for (int r=1; r<M; r++) {
                if (strs[r-1][c] > strs[r][c]) {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};