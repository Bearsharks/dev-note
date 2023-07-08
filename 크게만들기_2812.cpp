#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

/*
/ 전략 : 좌표평면에 배치해보자 처음 상승하는 녀석을 제거하면됨.
/ 제거한 곳의 이전부터 다시 반복 k개 지울때까지
/ 전부 지웠는데 다 하락이다 그러면 뒤에서 지운다.
/ 증명 : 처음 상승하는 걸 지운 것이 하락하거나 같은 것을 지운 것보다 작다고 하자
/ 하락이나 같은 것 / 상승하는 것 중 처음이 아닌 것을 지우는 경우일 것이다.
/ 하락이나 같은 것을 지운다고 하자 하락하는 걸 지우면 항상 손해임, 같은 경우 같으니까 작지않음
/ 상승하는 것중 두번째 이후를 지우면 처음 상승하는걸 지우는 것보다 항상 손해임
/ 모든 경우에서 거짓이기 때문에 처음상승하는 녀석을 제거하는게 맞다.
/
/ 이제 반복해서 적용했을 때 항상 최대를 구하는지 생각해보자
/ 하나 지워서 최대인 것에서, 하나 더 지우니 최대가 아닌 경우가 존재한다고 하자
/ 처음에 하나 지울때 지우지 말아야 할 것을 지운 경우 밖에 없다.
/ 두번째에서 만약 있었으면 더 클 수 있었던것을 앞에서 지워 버렸다는 것.
/ 처음 상승하는거가 뒤에서 필요한 경우가 있는가?
/ 그렇지 않다 어차피 다음차례에서 그 녀석이 가장 처음에 지워질 것이다.
/ 고로 이게 맞다.
*/

inline int parse(char c) {
    return c - '0';
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string numberStr;
    cin >> numberStr;

    vector<int> v;
    int idx = 0;
    while (k > 0 && idx < n) {
        if (v.empty() || v.back() >= parse(numberStr[idx])) { // 비었거나 하락하거나 같은경우
            v.push_back(parse(numberStr[idx++]));
        } else { // 상승하는 경우 지워야 함
            v.pop_back();
            k--;
        }
    } 

    while (k > 0) { //계속 하락하고 있으니 뒤에서 지울 수 밖에
        v.pop_back();
        k--;
    }

    while (idx < n) { //더 지울건 없으니 다 안붙였으면 붙여줌
        v.push_back(parse(numberStr[idx++]));
    }

    for (int a : v) {
        cout << a;
    }
    return 0;
}