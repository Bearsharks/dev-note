#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void f(int a, int cur, int back, int size, vector<map<int, int>>& v) {
    v[size][cur]++;
    for (int i = back + 1; i < 27; i++) {
        int next = 1 << i;
        if (a & next) {
            f(a, cur | next, i, size + 1, v);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<map<int, int>> v(11);
    for (string s : orders) {
        int cur = 0;
        for (char c : s) {
            cur = cur | (1 << (c - 'A'));
        }
        for (char c : s) {
            f(cur, (1 << (c - 'A')), c - 'A', 1, v);
        }
    }
    for (int i : course) {
        vector<int> mxs;
        int mx = 0;
        for (pair<int, int> p : v[i]) {
            if (p.second > mx) {
                mx = p.second;
                mxs.clear();
                mxs.push_back(p.first);
            }
            else if (p.second == mx) {
                mxs.push_back(p.first);
            }
        }

        if (mx >= 2)
        for (int j : mxs) {
            string ans;
            for (int k = 0; k < 27; k++) {
                if (j & (1 << k)) ans += k + 'A';
            }
            answer.push_back(ans);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main() {


    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };
    vector<string> res = solution(orders, course);
    return 0;
}