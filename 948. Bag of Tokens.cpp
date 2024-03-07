class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int max_score = 0, cur_score = 0, l = 0, r = tokens.size() - 1;

        sort(tokens.begin(), tokens.end());

        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l++];
                cur_score++;
                max_score = max(max_score, cur_score);
            } else if (l < r && cur_score > 0) {
                power += tokens[r--];
                cur_score--;
            } else break;
        }

        return max_score;
    }
};