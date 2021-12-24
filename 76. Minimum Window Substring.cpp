class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dict(256, 0);
        int left = 0, min_left = -1, count = 0, min_len = INT_MAX;
        
        for (char & c : t) {
            dict[c]++;
        }
        
        for (int i=0; i<s.size(); i++) {
            if (--dict[s[i]] >= 0) count++;
            while (count == t.size()) {
                if (i - left + 1 < min_len) {
                    min_len = i - left + 1;
                    min_left = left;
                }
                if (++dict[s[left]] > 0) count--;
                left++;
            }
        }
        
        return min_left == -1 ? "":s.substr(min_left, min_len);
    }
};