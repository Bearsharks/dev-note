#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // 가득 찬 트리다. 배열로 표현가능
    // 원하는 땅에서 부터 2로 나누면서 0까지 오면서,
    // 마주치는 오리가 있으면 그 오리를 업데이트 시킨다.
    // 오리가 땅을 가졌다면 그 오리를 set에 두고 조회 함 hash_set을 쓰면 시간은 상수 시간만에 찾을 수 있다.
    // 번호가 2 ^ 20개 만큼 있으니 찾는 최대시간은 20, 오리 수 20만 20 * 20만 = 400만 이니까 가능

    unordered_set<int> happyOris;
    for (int i = 0; i < m; i++) {
        int ori;
        cin >> ori;
        int cur = ori;

        int lastHappyOri = 0;
        while (cur > 0) {
            if (happyOris.count(cur)) {
                lastHappyOri = cur;
            }
            cur /= 2;
        }
        if (lastHappyOri == 0) happyOris.insert(ori);
        cout << lastHappyOri << "\n";
    }
    return 0;
}