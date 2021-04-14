#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<int,int> m;
    int ans = 0;
    while (n--) {
        string s;
        cin >> s;

        int remain = 0;
        int ready = 0;
        for (char c : s) {
            int k = (c == '(') ? 1 : -1;
            if (k < 0) {
                if (ready > 0) ready--;
                else remain--;
            }
            else {
                ready++;
            }
        }
        if (remain * ready == 0) {
            int i = abs(remain + ready);
            int a = remain + ready > 0 ? 1 : -1;
            unordered_map<int, int>::iterator k = m.find(i);
            if (k != m.end()){
                int test = k->second * a;
                if (test < 0) {
                    ans++;                    
                }
                k->second += a;
            }
            else {
                m[i] = a;
            }
        }
            
    }
    cout << ans + abs(m[0])/2;
    return 0;
}