class Solution {
    private:
        bool val(vector<vector<int>> &A) {
            sort(A.begin(), A.end(), [](const vector<int> &a, const vector<int> &b){
                return a[0] < b[0];
            });
            int N = A.size(), cur = A[0][1];
            int counter = 0;
    
            for (int i=1; i<N; i++) {
                if (A[i][0] >= cur) {
                    counter++;
                }
                cur = max(cur, A[i][1]);
            }
    
            return counter >= 2;
        }
    
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            vector<vector<int>> A, B;
            for (auto &rec: rectangles) {
                A.push_back({rec[0], rec[2]});
                B.push_back({rec[1], rec[3]});
            }
    
            return val(A) || val(B);
    
        }
    };