#include <iostream>
#include <vector>
#include <stack>
using namespace std;


string solution(string& s) {
    int i = 0;
    stack<char> st;
    string answer = "";
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                answer += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (c == '*' || c == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')){
                answer += st.top();
                st.pop();
            }
            st.push(c);
        }
        else if (c == '+' || c == '-') {            
            while (!st.empty() && st.top() != '(') {
                answer += st.top();
                st.pop();
            }
            st.push(c);
        }
        else {
            answer += c;
        }
    }
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }
    return answer;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << solution(s);
    return 0;
}


