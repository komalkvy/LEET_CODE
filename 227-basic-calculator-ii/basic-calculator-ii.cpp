#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int i = 0, n = s.size();

        while (i < n) {
            char c = s[i];

            if (c == ' ') {
                i++;
                continue;
            }

            if (isdigit(c)) {
                int val = 0;
                while (i < n && isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                num.push(val);
                continue;
            }

            while (!op.empty() && prec(op.top()) >= prec(c)) {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();
                num.push(apply(a, b, op.top()));
                op.pop();
            }

            op.push(c);
            i++;
        }

        while (!op.empty()) {
            int b = num.top(); num.pop();
            int a = num.top(); num.pop();
            num.push(apply(a, b, op.top()));
            op.pop();
        }

        return num.top();
    }

    int apply(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;  // truncate toward 0
        }
        return 0;
    }

    int prec(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }
};