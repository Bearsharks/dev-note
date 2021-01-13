#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        ss << " " << tmp;
    }
    string str = ss.str();
    for (char i = 'a'; i <= 'z'; i++) {
        if (str.find(i) == string::npos) {
            cout << i;
            return 0;
        }
    }

    string t = "aa";
    for (int i = 0; i < 26; i++) {
        t[1] = 'a';
        for (int j = 0; j < 26; j++) {
            if (str.find(t) == string::npos) {
                cout << t;
                return 0;
            }
            t[1]++;
        }
        t[0]++;
    }

    return 0;
}