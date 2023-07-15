#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

/*
    1. 전략
    답과 관련 있는 것은 연속된 초밥에서 종류의 수와 그 때의 종류에 쿠폰초밥이 포함되어있는지이다.
    둘을 합쳐서 현재 가능한 초밥의 종류의 갯수를 구할 수 있다.
    종류를 값을 앞에서 부터 뒤까지 죽 읽어가면서 그 때의 최대 값을 구하면 될 것.
    시작과 종료 포인터를 유지하면서 시작에서 벗어나면 집합에서 제외 끝에서 포함되면 집합에 추가 하면서
    계속 유지해 나간다. (수정 큐로 바꿈)
    집합은 해시맵으로 두고, 해시맵은 종류와 갯수를 포함하고 있음.
    이런 풀이의 시간 복잡도를 계산하면 해시맵 조회 추가, 삭제는 상수시간 앞에서 추가하고 빼는 것 상수시간
    그래서 시간 복잡도는 n이다.
*/

int oneAddAndOneOut(int a, int c, queue<int>& q, unordered_map<int,int>& qinfo) {
    q.push(a);
    qinfo[a]++;

    // 처음 초밥 제거
    int front = q.front();
    q.pop();
    int cnt = --qinfo[front];
    if (cnt == 0) qinfo.erase(front);
    int bonus = !qinfo.count(c);
    return bonus + qinfo.size();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    queue<int> q;
    unordered_map<int, int> qinfo;
    vector<int> v;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        q.push(a);
        qinfo[a]++;
        v.push_back(a);
    }

    int answer = !qinfo.count(c) + qinfo.size();
    if (answer >= k + 1) {
        cout << answer;
        return 0;
    }
    for (int i = k; i < n; i++) {
        // 다음 초밥 추가
        int a;
        cin >> a;
        int cnt = oneAddAndOneOut(a, c, q, qinfo);
        answer = answer > cnt ? answer : cnt;
        if (answer >= k + 1) {
            cout << answer;
            return 0;
        }
    }

    for (int i = 0; i < k - 1; i++) {
        int cnt = oneAddAndOneOut(v[i], c, q, qinfo);
        answer = answer > cnt ? answer : cnt;
        if (answer >= k + 1) {
            cout << answer;
            return 0;
        }
    }

    cout << answer;
    return 0;
}
// 틀림 왜냐하면 회전초밥이기때문 맨처음을 저장해두고 돌린다 마지막에 돌린다.