class Solution {
public:
    bool checkInclusion(string s1, string s2) {


        vector<int> diff_count(26, 0);
        int diff = s1.size(), N = s2.size(), M = diff;
        if (M > N) return false;

        for (char c: s1) diff_count[c - 'a']++;

        for (int i=0; i<N; i++) {
            if (i >= M) {
                int l = s2[i-M] - 'a';
                diff += diff_count[l] >= 0? 1: -1;
                diff_count[l]++;
                //printf("LEFT:%c-%d\n", s2[i-M], diff);
            }

            int r = s2[i] - 'a';
            diff += diff_count[r] > 0? -1: 1;
            diff_count[r]--;
            //printf("RIGHT:%c-%d\n", s2[i], diff);
            if (diff == 0) return true;
        }

        return false;
    }
};