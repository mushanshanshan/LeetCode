class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> counter(256, {0,0});
        vector<char> chars;
        for (int i=0; i<256; i++) counter[i].second = i;

        for (char c: s) counter[c].first++;
        sort(counter.begin(), counter.end(), [](const pair<int, int> &left, const pair<int, int> &right){
            return left.first > right.first;
        });

        for (auto &a: counter) {
            char c = a.second;
            for (int i=0; i<a.first; i++) {
                chars.push_back(c);
            }
        }

        return string(chars.begin(), chars.end());;
    }
};