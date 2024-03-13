class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> map;
        for (char c: s) {
            map[c]++;
        }
        string res;

        for (char c: order) {
            if (map.find(c) != map.end()) {
                while(map[c] > 0) {
                    res.push_back(c);
                    map[c]--;
                }
            }
        }

        for (auto &[k, v]: map) {
            while (map[k] > 0) {
                res.push_back(k);
                map[k]--;
            }
        }

        return res;
    }
};