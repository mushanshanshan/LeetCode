class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> temp_v;
        vector<string> res(score.size());

        for (int i=0; i<score.size(); i++) temp_v.push_back({score[i], i});
        sort(temp_v.begin(), temp_v.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.first > b.first;
        });

        for (int i=0; i<temp_v.size(); i++) {
            if (i == 0) res[temp_v[i].second] = "Gold Medal";
            else if (i == 1) res[temp_v[i].second] = "Silver Medal";
            else if (i == 2) res[temp_v[i].second] = "Bronze Medal";
            else res[temp_v[i].second] = to_string(i+1);
        }

        return res;
    }
};