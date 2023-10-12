class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        vector<int> res;

        for (auto a:flowers) {
            start.push_back(a[0]);
            end.push_back(a[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (int p: people) {
            int s = upper_bound(start.begin(), start.end(), p) - start.begin();
            int e = lower_bound(end.begin(), end.end(), p) - end.begin();
            res.push_back(s - e);
        }

        return res;
    }
};