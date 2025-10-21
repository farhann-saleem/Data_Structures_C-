#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if operator is right-associative
bool isRightAssociative(char op) {
    return (op == '^');
}

// Function to convert infix to prefix
string infixToPrefix(string s) {
    // Reverse the string
    reverse(s.begin(), s.end());

    // Swap '(' and ')'
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;
    string result = "";

    // Convert to postfix (on reversed expression)
    for (int i = 0; i < (int)s.length(); i++) {
        char c = s[i];

        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && st.top() != '(' &&
                ((precedence(st.top()) > precedence(c)) ||
                (precedence(st.top()) == precedence(c) && isRightAssociative(c)))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Reverse the result to prefix
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "a*(b+c)/d";
    cout << infixToPrefix(s) << endl;
    return 0;
}
