class Solution {
private:
    struct Comp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }
    };

public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26, 0);
        int res = 0, conducted = 0;
        queue<pair<int, int>> q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

        for (char t: tasks) {
            counter[t - 'A']++;
        }
        for (int i=0; i<26; i++) {
            if (counter[i] > 0) pq.push({i, counter[i]});
        }
        for (int i=0; i<n; i++) {
            q.push({-1, 0});
        }

        while (conducted < tasks.size()) {
            if (!pq.empty()) {
                pair<int, int> cur = pq.top();
                pq.pop();
                conducted++;
                // printf("%d\n", cur.first);
                if (cur.second > 1) {
                    q.push({cur.first, cur.second-1});
                } else {
                    q.push({-1, 0});
                }
            } else {
                // printf("idel\n");
                q.push({-1, 0});
            }


            if (q.front().first != -1) {
                pq.push(q.front());
            }
            q.pop();
            res++;

        }

        return res;
    }
};