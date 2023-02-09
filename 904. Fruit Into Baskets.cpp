class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 9, N = fruits.size();
        vector<int> count(N, 0);
        int type_count = 0, num_count = 0, res = 0;

        for (right=0; right<N; right++) {

            if (count[fruits[right]]++ == 0) type_count++;
            num_count++;

            while (type_count > 2 && left < right) {
                num_count--;
                if (--count[fruits[left]] == 0) type_count--;
                left++;
            }

            res = max(res, num_count);
        }

        return res;

    }
};