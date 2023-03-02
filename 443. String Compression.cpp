class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0, pre_count = 1, modify_index = 0, N = chars.size();
        char pre_char = chars[0];

        for (int i=1; i<=N; i++) {
            if (i < N && chars[i] == pre_char) pre_count++;
            else {
                chars[modify_index++] = pre_char;
                res++;
                if (pre_count > 1) {
                    int start = modify_index;
                    while (pre_count > 0) {
                        chars[modify_index++] = pre_count % 10 + '0';
                        pre_count /= 10;
                        res++;
                    }
                    reverse(chars.begin() + start, chars.begin() + modify_index);
                }
                pre_count = 1;
                if (i < N) pre_char = chars[i];
            }
        }

        return res;
    }
};