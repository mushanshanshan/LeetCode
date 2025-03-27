class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int N = grid.size(), M = grid[0].size();
            int total = N * M;
            int residual = grid[0][0] % x;
            vector<int> arr;
            arr.reserve(total);
            
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (grid[i][j] % x != residual)
                        return -1;
                    arr.push_back(grid[i][j] / x);
                }
            }
            
            sort(arr.begin(), arr.end());
            int median = arr[total / 2];
            
            long long res = 0;
            for (int v : arr) {
                res += abs(v - median);
            }
            
            return res;
        }
    };
    