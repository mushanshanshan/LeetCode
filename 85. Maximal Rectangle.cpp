class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row = matrix.size(), col = matrix[0].size(), res = 0;
        vector<vector<int>> cnt(row, vector<int>(col+1, -1));
        stack<int> st;
        
        for (int i=0; i<col; i++) {
            cnt[0][i] = matrix[0][i] - '0';
            for (int j=1; j<row; j++) {
                if (matrix[j][i] == '1') {
                    cnt[j][i] = cnt[j-1][i] + 1;
                } else {
                    cnt[j][i] = 0;
                }
            }
        }
        
        for (int i=0; i<row; i++) {
            while (!st.empty()) st.pop();
            for (int j=0; j<col+1; j++) {
                while (!st.empty() && cnt[i][st.top()] > cnt[i][j]) {
                    int cur = st.top();
                    st.pop();
                    int len = st.empty() ? j : j - st.top() - 1;
                    res = max(res, cnt[i][cur] * len);
                }
                st.push(j);
            }
        }
        
        return res;
        
    }
};