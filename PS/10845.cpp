#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    queue<int> q;
    vector<int> v;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int a;
            cin >> a;
            q.push(a);
        }
        else if (s == "size") {
            v.push_back(q.size());
        }
        else if (s == "empty") {
            v.push_back(q.empty());
        }
        else if(q.empty()){
            v.push_back(-1);            
        }
        else if (s == "pop") {
            v.push_back(q.front());
            q.pop();
        }
        else if (s == "front") {
            v.push_back(q.front());
        }
        else if (s == "back") {
            v.push_back(q.back());
        }
    }
    for (int i : v) {
        cout << i <<"\n";
    }
    return 0;
}