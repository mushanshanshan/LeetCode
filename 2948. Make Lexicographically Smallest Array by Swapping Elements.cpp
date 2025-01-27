class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        if (nums.size() <= 1) return nums;

        vector<pair<int, int>> num_idx;
        int N = nums.size();
        for (int i=0; i<N; i++) num_idx.push_back({nums[i], i});
        sort(num_idx.begin(), num_idx.end());
        vector<int> idx;
        vector<int> value;
        idx.push_back(num_idx[0].second);
        value.push_back(num_idx[0].first);


        for (int i = 1; i < N; i++) { // 修改了循环条件
            if (num_idx[i].first - num_idx[i - 1].first <= limit) {
                idx.push_back(num_idx[i].second);
                value.push_back(num_idx[i].first);
            } else {
                // 当前分组无法再扩大，处理该分组
                sort(idx.begin(), idx.end());
                sort(value.begin(), value.end());
                int M = idx.size();
                for (int j = 0; j < M; j++) {
                    nums[idx[j]] = value[j];
                }
                idx.clear();
                value.clear();

                // 开始新的一组
                idx.push_back(num_idx[i].second);
                value.push_back(num_idx[i].first);
            }
        }

        // 处理最后一组
        sort(idx.begin(), idx.end());
        sort(value.begin(), value.end());
        int M = idx.size();
        for (int j = 0; j < M; j++) {
            nums[idx[j]] = value[j];
        }


        return nums;
    }
};