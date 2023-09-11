#include <iostream>
#include <string>
using namespace std;
// 전략 50개임 아무거나 해도됨
// 펠린드롬은 뒤집어서 똑같은 것이니까 뒤집어서 생각해보자
// 필요한 것은 추가로 필요한 갯수 어떤 상태에서 추가로 필요한 갯수? 
// 가운데남기고 다른 갯수만큼 추가로 필요한갯수
// 전체 갯수 + 추가갯수 = 답
int compareWithReversed(const string& str) {
    int length = str.size();
    for (int i = 0; i < length; ++i) {
        bool isSame = true;
        for (int j = i, k = 0; j < length; ++j, ++k) {
            if (str[j] != str[length - k - 1]) {
                isSame = false;
                break;
            }
        }
        if (isSame) {
            return i;
        }
    }
    return length;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    cout << a.size() + compareWithReversed(a) << "\n";

    return 0;
}
