/*
 * @Date: 2022-12-04 21:46:29
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2022-12-29 15:32:25
 * @FilePath: /LeetCode/997. Find the Town Judge.cpp
 */
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1, 0);
        
        for (auto & a: trust) {
            cnt[a[1]]++;
            cnt[a[0]]--;
        }
        
        for (int i=1; i<n+1; i++) if (cnt[i] == n - 1) return i;
        
        return -1;
    }
};