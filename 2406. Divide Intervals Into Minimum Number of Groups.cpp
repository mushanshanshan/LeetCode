class Solution {
private:
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }
    };

public:
    int minGroups(vector<vector<int>>& intervals) {
        int res = 1;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        priority_queue<int, vector<int>, greater<int>> group;

        group.push(0);
        for (auto& a: intervals) {
            pq.push(a);
        }

        while (!pq.empty()) {
            // printf("%d-%d\n", pq.top()[0], pq.top()[1]);

            if (group.top() >= pq.top()[0]) {
                res++;
            } else {
                group.pop();
            }
            group.push(pq.top()[1]);
            pq.pop();
        }

        return res;
    }
};