class Solution {
private:
    vector<int> counter = {0,0,0};
    bool valid() {
        return counter[0] > 0 && counter[1] > 0 && counter[2] > 0;
    }

public:
    int numberOfSubstrings(string s) {
        int N = s.size();
        int res = 0;
        int l = 0, r = 0;

        while (r < N) {
            if (!valid()) {
                counter[s[r++] - 'a']++;
            } else {
                res += (N - r + 1); 
                counter[s[l++] - 'a']--;
            }
        }

        while (l < N && valid()) {
            res += 1;  
            counter[s[l++] - 'a']--;
        }

        return res;
    }
};