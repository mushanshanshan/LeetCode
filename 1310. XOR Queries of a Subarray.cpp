class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), 0);

        for (int j=0; j<queries.size(); j++) {
            int temp = arr[queries[j][0]];
            for (int i = queries[j][0]+1; i<=queries[j][1]; i++) {
                temp ^= arr[i];
            }
            res[j] = temp;
        }
        return res;
    }
};