#include <iostream>
#include <vector>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> rgbcost(n);
    for (int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        rgbcost[i].push_back(r);
        rgbcost[i].push_back(g);
        rgbcost[i].push_back(b);
    }
    vector<int> answer(3);
    for (vector<int> rgb : rgbcost) {
        vector<int> newanswer(3);
        for (int i = 0; i < 3; i++) {
            newanswer[i] = rgb[i] + min(answer[(i + 1) % 3], answer[(i + 2) % 3]);
        }
        answer = newanswer;
    }
    cout << min(answer[0], min(answer[1], answer[2]));
    return 0;
}
