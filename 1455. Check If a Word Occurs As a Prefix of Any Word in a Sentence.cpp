class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int M = searchWord.size(), N = sentence.size();
        int state = 1, match_count = 0, target_index = 0, word_count = 1;

        for (int i=0; i<N; i++) {
            if (sentence[i] == ' ') {
                state = 1;
                match_count = 0;
                target_index = 0;
                word_count++;
                continue;
            }
            if (state == 2) {
                continue;
            } else if (state == 1) {
                if (sentence[i] == searchWord[target_index]) {
                    match_count++;
                    target_index++;
                    if (match_count == M) return word_count;
                } else {
                    state = 2;
                }
            }
        } 

        return -1;
    }
};