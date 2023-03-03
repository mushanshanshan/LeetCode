class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0, r = 0, N = haystack.size(), M = needle.size();

        for (; l<N; l++) {
            if (haystack[l] == needle[0]) {
                r = 0;
                while (r < M) {
                    printf("%d-%d\n", l+r, r);
                    if (haystack[l+r] != needle[r]) break;
                    else r++;
                }
                if (r == M) return l;
            }
        }

        return -1;
    }
};