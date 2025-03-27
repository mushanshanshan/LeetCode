class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b){
                return a[0] < b[0];
            });
    
            int cur_e = meetings[0][1], res = meetings[0][0] - 1;
            for (auto &m: meetings) {
                // printf("%d-%d\n", m[0], m[1]);
                if (m[0] > cur_e) {
                    // printf("%d-%d\n", m[0], cur_e);
                    res += m[0] - cur_e - 1;
                }
                cur_e = max(m[1], cur_e);
            }
    
            res += days - cur_e;
    
    
            return res;
        }
    };