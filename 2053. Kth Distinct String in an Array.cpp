class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> coutner;

        for (auto &a: arr) {
            coutner[a]++;
        }

        for (auto &a: arr) {
            if (coutner[a] == 1) k--;
            if (k == 0) return a;
        }

        return "";
    }
};