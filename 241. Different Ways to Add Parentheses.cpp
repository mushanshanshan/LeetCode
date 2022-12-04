class Solution {
public:
    unordered_map<string, vector<int>> m;
    
    vector<int> diffWaysToCompute(string expression) {
        if (m.count(expression)) return m[expression];
        
        vector<int> res;
        
        for (int i=0; i<expression.size(); i++) {
            
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                
                for (int j=0; j<left.size(); j++) {
                    for (int k=0; k<right.size(); k++) {
                        if (expression[i] == '+') {
                            res.push_back(left[j] + right[k]);
                        } else if (expression[i] == '-') {
                            res.push_back(left[j] - right[k]);
                        } else {
                            res.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }
        
        if (res.empty()) {
            res.push_back(std::stoi(expression));
        }
        
        m[expression] = res;
        
        return res;
        
    }
};