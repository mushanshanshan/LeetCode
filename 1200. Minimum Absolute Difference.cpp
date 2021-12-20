class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        int diff = INT_MAX;
        
        for (int i=1; i<arr.size(); i++) {
            if (arr[i] - arr[i-1] < diff) {
                res.clear();
                res.push_back({arr[i-1], arr[i]});
                diff = arr[i] - arr[i-1];
            } else if (arr[i] - arr[i-1] == diff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        
        return res;
        
    }
};