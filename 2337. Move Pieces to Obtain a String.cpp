class Solution {
public:
    bool canChange(string start, string target) {
        int N = start.size(), M = target.size();
        int i = 0, j = 0;

        while (i < N && j < M) {
            while (start[i] == '_') i++;
            while (target[j] == '_') j++;

            if (start[i] != target[j]) return false;
            if (start[i] == 'L' && j > i) return false;
            if (start[i] == 'R' && j < i) return false;

            i++;
            j++;
        }

        while (i < N) if (start[i++] != '_') return false;
        while (j < M) if (target[j++] != '_') return false;

        return true;
    }
};