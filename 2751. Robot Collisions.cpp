class Solution {

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int N = positions.size();
        vector<pair<int, int>> tv;
        for (int i=0; i<N; i++) {
            tv.push_back({positions[i], i});
        }

        sort(tv.begin(), tv.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        });

        stack<pair<int, char>> st;
        stack<pair<int, char>> temp;

        for (auto &a: tv){
            st.push({a.second, directions[a.second]});
        }

        while (!st.empty()) {
            if (temp.empty() || (temp.top().second == 'R' && st.top().second == 'L') || st.top().second == temp.top().second) {
                temp.push(st.top());
                st.pop();
            } else if (st.top().second != temp.top().second) {
                if (healths[st.top().first] > healths[temp.top().first]) {
                    healths[st.top().first] -= 1;

                    healths[temp.top().first] = -1;
                    temp.pop();
                } else if (healths[st.top().first] < healths[temp.top().first]) {
                    healths[temp.top().first] -= 1;

                    healths[st.top().first] = -1;
                    st.pop();
                } else {
                    healths[temp.top().first] = -1;
                    healths[st.top().first] = -1;
                    st.pop();
                    temp.pop();
                }
            }
        }
        
        vector<int> res;

        for (int i: healths) {
            if (i > 0) res.push_back(i);
        }

        return res;
    }
};