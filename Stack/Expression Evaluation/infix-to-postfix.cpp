#include <iostream>
#include <stack>
using namespace std;

int precedance(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if( c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
};

string infixToPostfix(string s) {
    stack<char> st;
    string rs;

    for(int i = 0; i < s.length(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            rs += s[i];
        } else if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                rs += st.top();
                st.pop();
            }

            if(!st.empty()) {
                st.pop();
            }
        } else {
            while(!st.empty() && precedance(st.top()) > precedance(s[i])) {
                rs += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        rs += st.top();
        st.pop();
    }

    return rs;
}

int main() {
    string str = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(str) << endl;
    return 0;
}