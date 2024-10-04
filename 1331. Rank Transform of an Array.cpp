class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size(), cur_rank = 1;
        vector<int> dup(arr);
        unordered_map<int, int> rank;
        sort(dup.begin(), dup.end());

        for (int i=0; i<N; i++) {
            if (!rank.contains(dup[i])) rank[dup[i]] = cur_rank++;
        }

        for (int i=0; i<N; i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};