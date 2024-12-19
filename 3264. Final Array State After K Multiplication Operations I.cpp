class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int N = nums.size();
        vector<int> res(N, 0);

        for (int i =0; i<N; i++) {
            pq.push({nums[i], i});
        }

        while (k-->0) {
            auto cur = pq.top();
            pq.pop();
            pq.push({cur.first * multiplier, cur.second});
        }

        while (!pq.empty()) {
            auto& cur = pq.top();
            res[cur.second] = cur.first;
            pq.pop();
        }

        return res;
    }
};