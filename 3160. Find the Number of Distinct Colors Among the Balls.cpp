class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_color;
        unordered_map<int, int> color_counter;
        vector<int> res;
        int cur = 0;

        for (auto& a: queries) {
            if (ball_color.find(a[0]) != ball_color.end()) {
                color_counter[ball_color[a[0]]]--;
                if (color_counter[ball_color[a[0]]] == 0) cur--;
            }
            color_counter[a[1]]++;
            ball_color[a[0]] = a[1];
            if (color_counter[a[1]] == 1) cur++;
            res.push_back(cur);
        }

        return res;
    }
};