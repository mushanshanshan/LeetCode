class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        string res = "";
        int temp;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (pq.size() > 1) {
            auto largest = pq.top();
            pq.pop();

            auto second = pq.top();
            pq.pop();

            temp = min(2, largest.first);
            for (int i=0; i<temp; i++) res += largest.second;
            largest.first -= temp;
            
            if (second.first > largest.first) temp = min(2, second.first);
            else temp = 1;
            for (int i=0; i<temp; i++) res += second.second;
            second.first -= temp;

            if (largest.first > 0) pq.push(largest);
            if (second.first > 0) pq.push(second);
        }

        if (!pq.empty()) {
            for (int i=0; i<min(2, pq.top().first); i++) {
                res += pq.top().second;
            }
        }

        return res;
    }
};