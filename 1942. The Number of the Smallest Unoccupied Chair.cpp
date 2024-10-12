class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int next_chair = 0, tar_arr_time = times[targetFriend][0];
        priority_queue<int, vector<int>, greater<int>> emtpy_chairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leave;;

        sort(times.begin(), times.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

        for (auto& t: times) {
            int cur_chair = 0;
            while (!leave.empty() && leave.top().first <= t[0]) {
                emtpy_chairs.push(leave.top().second);
                leave.pop();
            }
            if (emtpy_chairs.empty()) {
                cur_chair = next_chair++;
            } else {
                cur_chair = emtpy_chairs.top();
                emtpy_chairs.pop();
            }

            if (t[0] == tar_arr_time) return cur_chair;

            leave.push({t[1], cur_chair});
        }

        return -1;
    }
};