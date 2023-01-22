class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    int len;

    bool isPartition(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void backTrack(string &s, int start) {
        if (start == len) res.push_back(temp);

        for (int i=start; i<len; i++) {
            if (isPartition(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                backTrack(s, i+1);
                temp.pop_back();
            }
        }
    }


public:
    vector<vector<string>> partition(string s) {
        len = s.size();
        backTrack(s, 0);

        return res;
    }
};