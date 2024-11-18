class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence[0] != sentence[sentence.size()-1]) return false;

        bool res = true;
        int N = sentence.size(), cur = 0;

        while (res && cur < N) {
            if (sentence[++cur] == ' ') {
                if (sentence[cur-1] != sentence[cur+1]) res = false;
            }
        }

        return res;
    }
};