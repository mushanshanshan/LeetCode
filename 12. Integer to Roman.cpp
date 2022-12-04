class Solution {
private:
    const vector<int> key{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const vector<string> value{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

public:
    string intToRoman(int num) {
        int cur = 0;
        string s = "";
        while (num > 0) {
            if (num < key[cur]) cur++;
            else {
                num -= key[cur];
                s += value[cur];
            }
        }
        return s;
    }
};