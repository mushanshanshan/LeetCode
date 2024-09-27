class Solution {
private:
    unordered_map<string, vector<int>> cache;

    vector<int> re(string expression) {
        if (cache.contains(expression)) return cache[expression];

        int N = expression.size();
        vector<int> res;

        for (int i=0; i<N; i++) {
            if (expression[i] == '-' || expression[i] == '+' || expression[i] == '*') {
                vector<int> l_res = re(expression.substr(0, i));
                vector<int> r_res = re(expression.substr(i+1, N-i-1));

                for (int l: l_res) {
                    for (int r: r_res) {
                        if (expression[i] == '-') res.push_back(l - r);
                        else if (expression[i] == '+') res.push_back(l + r);
                        else if (expression[i] == '*') res.push_back(l * r);
                    }
                }
            }
        }
        if (res.size() == 0) res.push_back(stoi(expression));
        cache[expression] = res;
        return res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return re(expression);
    }
};