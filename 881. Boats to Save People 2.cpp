class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, l = 0, r = people.size() - 1;
        sort(people.begin(), people.end());

        while (l <= r) {
            int remain = limit, p_limit = 0;
            while (l <= r && p_limit < 2 && remain >= people[r]) {remain -= people[r--];p_limit++;}
            while (l <= r && p_limit < 2 && remain >= people[l]) {remain -= people[l++];p_limit++;}
            res++;
        }

        return res;
    }
};