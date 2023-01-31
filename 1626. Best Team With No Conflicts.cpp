class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int N = scores.size(), res = 0;
        vector<pair<int, int>> data(N, {0,0});
        vector<int> dp(N, 0);
        
        

        for (int i=0; i<N; i++) {
            data[i].first = ages[i];
            data[i].second = scores[i];
        }

        sort(data.begin(), data.end());

        for (int i=0; i<N; i++) {
            dp[i] = data[i].second;

            for(int j=0; j<i; j++) {
                if (data[j].second <= data[i].second) {
                    dp[i] = max(dp[j] + data[i].second, dp[i]);
                }
            }

            res = max(res, dp[i]);
        }

        return res;
    }
};