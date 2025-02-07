class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> counter;
        int N = nums.size();
        int res = 0;

        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                counter[nums[i] * nums[j]]++;
            }
        }

        for (auto& [k, v]: counter) {
            if (v > 1) {
                // printf("%d-%d\n", k ,v);
                res += v * (v-1);
            }
        }

        return res * 4;
    }
};