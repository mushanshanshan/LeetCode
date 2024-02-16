class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> counter;
        vector<int> temp;
        int res = 0;

        for (int i: arr) {
            counter[i]++;
            if (counter[i] == 1) res++;
        }

        for (auto const& [k, v]: counter) temp.push_back(v);
        sort(temp.begin(), temp.end());

        for (int i: temp) {
            k -= i;
            if (k >= 0) res--;
            else break;
        }

        return res;
    }
};