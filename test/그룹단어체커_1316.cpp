#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        vector<bool> hasAppeared(27);
        bool isOk = true;
        char prev = 0;
        // ���� �ܾ �������� �־���, ���� �ܾ�� �ٸ��� ����
        for (char c : word) {
            int idx = c - 'a';
            if (hasAppeared[idx] && prev != c) {
                isOk = false;
                break;
            }
            prev = c;
            hasAppeared[idx] = true;
        }
        answer += isOk;
    }

    cout << answer;

    return 0;
}