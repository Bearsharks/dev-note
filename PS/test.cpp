#include <iostream>
#include <vector>
using namespace std;

int M;
int N;
vector < pair<int, int>> d;
void f(int curi, int curj, vector<vector<bool>>& visit, vector<vector<int>>& picture, int& cnt) {
    visit[curi][curj] = true;     
    cnt++;
    for (int i = 0; i < 4; i++) {
        int nexti = curi + d[i].first;
        int nextj = curj + d[i].second;
        if (0 <= nexti && nexti < M && 0 <= nextj && nextj < N &&
                !visit[nexti][nextj] && picture[nexti][nextj] == picture[curi][curj]) {
            f(nexti, nextj, visit, picture, cnt);
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    M = m;
    N = n;
    d = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    vector<vector<bool>> visit(m, vector<bool>(n));

    
    int areacnt = 0;
    int mx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] && !visit[i][j]) {
                areacnt++;
                int cnt = 0;
                f(i, j, visit, picture, cnt);
                mx = max(mx, cnt);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = areacnt;
    answer[1] = mx;
    return answer;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> test = solution(6, 4, { {1, 1, 1, 0}, { 1, 2, 2, 0 }, { 1, 0, 0, 1 }, { 0, 0, 0, 1 }, { 0, 0, 0, 3 }, { 0, 0, 0, 3 } });
    return 0;
}

/*
var answer = 0;
var start = [];
var end = [];
for (let t of lines) {
    let endtime = Number(t.substr(11, 2)) * 60;
    endtime = (endtime + Number(t.substr(14, 2))) * 60;
    endtime = (endtime + Number(t.substr(17, 2))) * 1000;
    endtime = (endtime + Number(t.substr(20, 3)));
    let rd = Number(t.substr(24).slice(0, -1)) * 1000;
    start.push(endtime - rd + 1);
    end.push(endtime);
}
start.sort();
start.push(Infinity);
for (let i = 0; i < end.length; i++) {
    let r = end[i] + 999;
    let mx = start.length - 1;
    let mn = 1;
    while (mn < mx) {
        let mid = parseInt((mx + mn) / 2);
        if (start[mid] > r) {
            mx = mid;
        }
        else {
            mn = mid + 1;
        }
    }
    answer = Math.max(answer, mx - i);
}
return answer;
*/