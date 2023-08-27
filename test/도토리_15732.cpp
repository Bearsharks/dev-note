#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


// 전략 이분탐색일 것이다.
// 무엇을 기준으로 왔다 갔다 할 것인가?
// 원하는 것은 도토리 갯수를 세는 것이다?
// 사이에 있는 도토리 갯수를 세는 것이다.
// 도토리가 처음상자부터 채워질것이다?
// 마지막 상자가 무엇인지를 왔다 갔다하면서 찾을 것이다.
// 도토리가 남지 않았을 때 중 가장 작은 것이 답이다.
// 사이의 도토리 갯수 구하기 아무튼 수식으로 나올 것임 1
// 그걸 m만큼 반복 m, log n * m이 시간 복잡도로 나온다.
// 시작상자보다 mid가 작아질 때 주의할 것
// 10억 이하고 만개의 도토리를 더해 갈 것 int로 충분
inline int calcDoto(int s, int e, int interval) {
    return (e - s) / interval + 1;
}

bool isRemainDoto(vector<tuple<int, int, int>>& v, int mid, int d) {
    int cnt = 0;
    for (tuple<int, int, int >& t : v) {
        int s = get<0>(t);
        if (s > mid) continue; // 인데 주의를 안해서 한번 틀림
        int e = min(get<1>(t), mid);
        int interval = get<2>(t);
        cnt += calcDoto(s, e, interval);
        if (d <= cnt) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;
    vector<tuple<int, int, int>> v(m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = { a, b, c };
    }
    
    int l = 1, r = n;
    while (l < r) {// 구하려는 것은 도토리가 딱 떨어지는 것 중 가장 작은 것
        // 도토리가 더 필요하면 줄인다. r = mid - 1
        // 도토리가 남으면 늘린다. l = mid + 1
        int mid = (r + l) / 2;
         if (isRemainDoto(v, mid, d)) { // 남으면 늘린다.
            l = mid + 1;
        }
        else { // 부족하거나 같으면 답일수도?
            r = mid;
        }
    }

    cout << r;
 
    return 0;
}