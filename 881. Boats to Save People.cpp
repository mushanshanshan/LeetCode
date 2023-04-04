class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, l = 0, r = people.size() - 1;

        sort(people.begin(), people.end());

        while (l <= r) {
            if (people[r] + people[l] <= limit) {
                l++;
            } 
            r--;
            res++;
        }

        return res;

    }
};