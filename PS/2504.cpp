#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    stack<char> st;
    stack<int> answer;
    answer.push(0);
    for (char c : s) {
        if (c == ')') {
            if (st.empty() || st.top() != '(') {
                cout << 0;
                return 0;
            }
            int cur = answer.top();
            answer.pop();
            cur =  cur? cur*2:2;
            st.pop();
            answer.top() += cur;
        }else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                cout << 0;
                return 0;
            }
            int cur = answer.top();
            answer.pop();
            cur = cur ? cur * 3 : 3;
            st.pop();
            answer.top() += cur;
        }
        else {
            answer.push(0);
            st.push(c);
        }
    }
    if (answer.size() > 1) {
        cout << 0;
        return 0;
    }
    cout << answer.top();
    return 0;
}