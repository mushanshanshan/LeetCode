class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> pq;
        vector<pair<int, int>> pc;
        int N = profits.size(), cur_idx = 0;

        for (int i=0; i<N; i++) {
            pc.push_back({profits[i], capital[i]});
        }

        sort(pc.begin(), pc.end(), [] (const pair<int, int> &x, const pair<int, int> &y) {return x.second < y.second;});

        // for (auto a: pc) {
        //     printf("%d-%d\n", a.first, a.second);
        // }
        // printf("===========\n");


        for (int i=0; i<k; i++) {
            while (cur_idx < N) {
                if (pc[cur_idx].second <= w) pq.emplace(pc[cur_idx++]);
                else break;
            }
            // printf("%d : %d-%d\n", i, pq.top().first, pq.top().second);
            if (!pq.empty()) {
                w += pq.top().first;
                pq.pop();
            }
        }
        
        return w;
    }
};