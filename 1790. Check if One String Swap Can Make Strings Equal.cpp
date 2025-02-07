class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int N = s1.size();
        vector<char> diff;

        for (int i=0; i<N; i++) {
            if (s1[i] != s2[i]) {
                if (diff.size() == 0) {
                    diff.push_back(s1[i]);
                    diff.push_back(s2[i]);
                } else if (diff.size() == 2) {
                    if (s1[i] == diff[1] && s2[i] == diff[0]) {
                        diff.push_back(s1[i]);
                    } else return false;
                } else return false;
            }
        }

        return diff.size() == 3 || diff.size() == 0;
    }
};