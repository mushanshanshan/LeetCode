class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> count(2001, 0);
        for (int& i:arr) count[i+1000]++;
        vector<bool> used(1000, false);
        for (int&i :count) {
            if (!i) continue;
            if (!used[i]) used[i]=true;
            else return false;
        }
        return true;
    }
};