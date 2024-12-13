class Solution {
public:
    long long findScore(vector<int>& nums) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_set<int> marked;
        int N = nums.size();
        long long res = 0;

        for (int i=0; i<N; i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            if (marked.contains(cur.second)) continue;
            res += cur.first;
            marked.insert(cur.second-1);
            marked.insert(cur.second+1);
        }

        return res;
    }
};