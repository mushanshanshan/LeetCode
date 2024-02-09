class Solution {
private:
    string getSignature(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        stringstream ss;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                ss << (char)('a' + i) << count[i];
            }
        }
        return ss.str();
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> res;

        for (auto &s: strs) {
            string sign = getSignature(s);
            if (map.find(sign) == map.end()) {
                map[sign] = res.size();
                res.push_back({s});
            } else{
                res[map[sign]].push_back(s);
            }
        }

        return res;

    }
};