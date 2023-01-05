/*
 * @Date: 2022-12-30 15:23:34
 * @LastEditors: Mushan wwd137669793@gmail.com
 * @LastEditTime: 2023-01-04 14:15:49
 * @FilePath: /LeetCode/797. All Paths From Source to Target.cpp
 */

class Solution {
private:

    vector<vector<int>> res;
    vector<int> path;
    int target;
    int N;

    void backTrace(int cur, vector<vector<int>>& graph) {
        
        printf("%d,", cur);

        if (cur == target) {
            res.push_back(path);
            return;
        }

        for (int next: graph[cur]) {
            path.push_back(next);
            backTrace(next, graph);
            path.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size();
        target = N - 1;

        path.push_back(0);
        backTrace(0, graph);

        return res;
    }
};