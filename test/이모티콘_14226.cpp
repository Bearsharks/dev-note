#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

/*
각 횟수가 독립적이지 않음 
다시 말해 각 이모티콘 갯수의 최소 연산횟수에 상태가 있음 dp로 만들기 곤란함
100개 이모티콘에 클립보드 2개 와 100개 이모티콘에 클립보드 100개는 다름
또한 목표갯수의 최소를 알아내려하면 목표 갯수 - 클립보드 갯수를 둘다 봐야 함
예를들어 1000개가 목표면  갯수/클립보드로 했을때
999/1 998/2 997/3... 를 모두 봐야 최소 판단 가능
1000 * 1000 개의 상태에서 1000개를 봐야 판단 가능하기 때문에 시간은
1,000,000,000 10억 시간 5억 시간? 쯤 들음

아니면 bfs로 최소거리 구하듯이 구하는 것
bfs에 갯수, 클립보드, 횟수 넣고 돌리기
숫자 넘으면 횟수 + 갯수 - 목표

갯수 말고 횟수로 따지기
배열 하나 사용
넘으면 자동 횟수 계산하고 지워버리기
*/


unordered_set<int> prevSet = { 10001 };
unordered_set<int> already = { 10000, 0, 10001 };
int s;
int mn;

void insert(unordered_set<int>& set, int cnt, int val, int clip) {
    if (val < 1) return;
    int newone = val * 10000 + clip;
    if (already.count(newone)) return;
    if (val >= s) {
        int need = cnt + val - s;
        mn = min(need, mn);
    }
    set.insert(newone);
    already.insert(newone);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> s;

    mn = s;
    int cnt = 1;
    while (++cnt < mn) {
        unordered_set<int> set;
        for (int p : prevSet) {
            int val = p / 10000;
            int clip = p % 10000;
            insert(set, cnt, val, val);
            insert(set, cnt, val + clip, clip);
            insert(set, cnt, val - 1, clip);
        }
        prevSet = set;
    }

    cout << mn;
    return 0;
}
