class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> smap;
        int N = groupSizes.size();

        for (int i=0; i<N; i++) {
            smap[groupSizes[i]].push_back(i);

            if (smap[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back(smap[groupSizes[i]]);
                smap[groupSizes[i]].clear();
            }
        }

        return res;
    }
};