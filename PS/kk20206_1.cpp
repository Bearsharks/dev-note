#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,w,d;
vector<int> dist;
vector<int> weak;
vector<int> mark;
int markcnt;
int ans = 10000;

int test(int& a, int& b) {
    return a > b;
}

int getNext(int start, int cur, int limit) {
    int j = cur + 1;
    for (; weak[j % w] + (j / w)*N <= limit; j++) {
        if (j % w == start) break;
    }
    int result = j % w;
    return (result == start) ? -1 : result;
}
int f(int start, int cur, int cnt) {    
    if (ans <= cnt) return 10000;
    int result = 10000;
    int prevcnt = -1;
    for (int i = d-1; i >= 0; i--) {
        if (mark[i]) continue;
        int limit = dist[i] + weak[cur];
        int next = getNext(start, cur, limit);
        if (next == -1) {
            result = cnt;
            break;
        }
        int nextcnt = (next <= cur) ? next - cur + N : next - cur;
        if (nextcnt <= prevcnt) continue;
        prevcnt = nextcnt;
        mark[i] = 1;
        result = min(result,f(start, next, cnt+1));
        mark[i] = 0;
    }
    ans = min(ans, result);
    return result;
}

int solution(int n, vector<int> we, vector<int> di) {
    N = n;
    weak = we;
    dist = di;
    w = weak.size();
    d = dist.size();
    mark.assign(d,0);
    sort(dist.begin(), dist.end(), test);
    for (int i = 0; i < w; i++) {
        f(i, i, 1);
    }    
    if (ans > 100) ans = -1;
    return ans;
}

int main() {
    cout << solution(12, { 1,5,6,10 }, { 1,2,3,4 }) << "\n";
    //cout << solution(12, { 1,3,4,9,10 }, { 3, 5, 7 });
    return 0;
}