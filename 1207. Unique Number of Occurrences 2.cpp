class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        unordered_set<int> count;

        for (int i: arr) counter[i]++;
        for (auto& a: counter) {
            if (count.find(a.second) == count.end()) {
                count.insert(a.second);
            } else {
                return false;
            }
        }

        return true;
    }
};