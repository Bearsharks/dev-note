#include <iostream>
using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    
    string candi[6] = { "RGB","RBG","GRB","GBR","BRG","BGR" };
    int dcnt[6];
    for (int t = 0; t < 6; t++) {
        dcnt[t] = 0;
        for (int i = 0; i < n; i++) {
            if (s.at(i) != candi[t].at(i % 3)) dcnt[t]++;
        }
    }

    int mn = dcnt[0];
    int mni = 0;
    for (int t = 1; t < 6; t++) {
        if (mn > dcnt[t]) {
            mn = dcnt[t];
            mni = t;
        }
    }
    cout << mn << "\n";
    for (int i = 0; i < n; i++) {
        cout << candi[mni].at(i % 3);
    }
    return 0;
}