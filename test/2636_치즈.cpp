#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> arr(101, vector<int>(101, 0));
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            cnt += arr[i][j];
        }
    }

    int time = 0;
    int prevCnt = 0;
    while (cnt > 0) {
        prevCnt = cnt;
        vector<vector<bool>> visit(101, vector<bool>(101, false));
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if (nx<0 || nx>N + 1 || ny<0 || ny>M + 1 || visit[nx][ny]) continue;

                    visit[nx][ny] = true;
                    if (arr[nx][ny] == 1) {
                        arr[nx][ny] = 0;
                        cnt--;
                    }
                    else {
                        q.push({ nx, ny });
                    }
                }
            }
        }
        /*cout << "\n";
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }*/
        time++;
    }
    cout << time << "\n" << prevCnt;

    return 0;
}