class Solution {
public:
    string reversePrefix(string word, char ch) {
        int right = 0, left = 0;

        while (right < word.size() && word[right] != ch) right++;

        if (right != word.size()) {
            while (left < right) {
                swap(word[left++], word[right--]);
            }
        }


        return word;
    }
};