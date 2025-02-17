class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        int res = 0;
        for (int n: nums) pq.push(n);

        while (pq.size() >= 2 && pq.top() < k){
            res++;
            long s = pq.top() * 2;
            pq.pop();
            s += pq.top();
            pq.pop();
            pq.push(s);
        }

        return res;
    }
};