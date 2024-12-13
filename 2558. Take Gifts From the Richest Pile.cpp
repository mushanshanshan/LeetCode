class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long res = 0;

        for (int g: gifts) {
            pq.push(g);
        }
        for (int i=0; i<k; i++) {
            int cur = sqrt(pq.top());
            pq.pop();
            pq.push(cur);
        }

        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};