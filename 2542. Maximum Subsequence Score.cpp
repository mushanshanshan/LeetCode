class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> num(n);
        long long sum = 0, res = 0;
        
        for (int i=0; i<n; i++) {
            num[i] = {nums1[i], nums2[i]};
        }

        sort(num.begin(), num.end(), [](const auto& x, const auto& y){return x.second > y.second;});

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& iter: num) {
            pq.emplace(iter.first);
            sum += iter.first;

            if (pq.size() == k) {
                res = max(res, sum * iter.second);
                sum -= pq.top();
                pq.pop();
            }
        }

        return res;
    }
};