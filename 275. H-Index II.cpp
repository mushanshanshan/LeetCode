class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());

        for (int i=1; i<citations.size()+1; i++) {
            if (citations[i-1] < i) return i-1;
        }

        return citations.size();
    }
};