class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0, N = piles.size();
        sort(piles.begin(), piles.end());
        for (int i=N-2; i>=N/3; i-=2) res += piles[i];
        return res;
    }
};