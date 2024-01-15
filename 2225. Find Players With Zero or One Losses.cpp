class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loss;
        vector<int> no_loss;
        vector<int> one_loss;

        for (auto a: matches) {
            if (loss.find(a[0]) == loss.end()) loss[a[0]] = 0;
            loss[a[1]]++;
        }

        for (auto a:loss) {
            if (a.second == 0) no_loss.push_back(a.first);
            if (a.second == 1) one_loss.push_back(a.first);
        }

        sort(no_loss.begin(), no_loss.end());
        sort(one_loss.begin(), one_loss.end());

        return {no_loss, one_loss};
    }
};