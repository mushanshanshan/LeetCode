class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        short n = text1.size(), m = text2.size();
        short menLen = max(n ,m);

        vector<short> dp_pre(menLen+1,0);
        vector<short> dp_cur(menLen+1,0);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (text1[i] == text2[j]) dp_cur[j+1] = dp_pre[j] + 1;
                else dp_cur[j+1] = max(dp_pre[j+1], dp_cur[j]);
            }
            swap(dp_pre, dp_cur);
        }

        return dp_pre[m];
    }
};