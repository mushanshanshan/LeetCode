class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int N = pref.size();
        vector<int> res(N, pref[0]);

        for (int i=1; i<N; i++) {
            res[i] = pref[i] ^ pref[i-1];
        }

        return res;
    }
};