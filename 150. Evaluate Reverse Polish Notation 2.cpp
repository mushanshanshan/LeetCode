class Solution {
private:
    stack<long> left;

public:
    int evalRPN(vector<string>& tokens) {

        for (string cur: tokens) {

            if (cur == "+" || cur == "-" || cur == "*" || cur == "/")  {
                long b = left.top();
                left.pop();
                long a = left.top();
                left.pop();

                if (cur == "+") left.push(a+b);
                if (cur == "-") left.push(a-b);
                if (cur == "*") left.push(a*b);
                if (cur == "/") left.push(a/b);
            } else {
                left.push(stoi(cur));
            }
        }

        return left.top();
    }
};