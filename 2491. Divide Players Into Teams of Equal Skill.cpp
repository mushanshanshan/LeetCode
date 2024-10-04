class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int N = skill.size();
        int l = 0, r = N -1;
        long long res = 0;

        sort(skill.begin(), skill.end());
        int esk = skill[l] + skill[r];

        while (l < r) {
            if (skill[l] + skill[r] != esk) return -1;
            res += skill[l] * skill[r];
            l++;
            r--;
        }

        return res;
    }
};