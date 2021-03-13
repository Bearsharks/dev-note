#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct param
{
    int ax;
    int ay;
    int bx;
    int by;
    int cnt;
};

int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

long long getmyh(param p) {
    if (p.ax > p.bx || (p.ax == p.bx && p.ay > p.by)) {
        swap(p.ax, p.bx);
        swap(p.ay, p.by);
    }
    return (long long)p.ax * 100000000 + p.ay * 100000 + p.bx * 100 + p.by;
}
bool cango(param p, unordered_map<long long, int>& visit) {
    long long myh = getmyh(p);
    return !visit.count(myh) || (visit.count(myh) && visit[myh] > p.cnt);
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    queue<param> q;
    q.push({ 0,0,0,1,0});

    unordered_map<long long,int> visit;
    visit[1] = 0;
    while (!q.empty()) {
        param cur = q.front();
        q.pop();
        if ((cur.ax == n - 1 && cur.ay == n - 1) || (cur.bx == n - 1 && cur.by == n - 1)) {
            answer = cur.cnt;
            break;
        }
        for (int k = 0; k < 4; k++) {
            param next = { cur.ax + dx[k],cur.ay + dy[k],cur.bx + dx[k],cur.by + dy[k], cur.cnt + 1 };
            if (0 <= next.ax && next.ax < n && 0 <= next.ay && next.ay < n &&
                    0 <= next.bx && next.bx < n && 0 <= next.by && next.by < n &&
                        board[next.ax][next.ay] == 0 && board[next.bx][next.by] != 1 && cango(next,visit)){
                visit[getmyh(next)] = next.cnt;
                q.push(next);
            }        
        }
        
        param curcp = cur;
        if (curcp.ax > curcp.bx || (curcp.ax == curcp.bx && curcp.ay > curcp.by)) {
            swap(curcp.ax, curcp.bx);
            swap(curcp.ay, curcp.by);
        }
        curcp.cnt++;
        bool isver = curcp.by - curcp.ay == 0;
        if (isver) {                
            if (0 <= curcp.ay - 1 && !board[curcp.ax][curcp.ay-1]  && !board[curcp.bx][curcp.by-1]) {
                param next = curcp;
                next.bx--;
                next.by--;
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
                next.ax++;
                next.bx++;
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
            }
            if (curcp.ay + 1 < n && !board[curcp.ax][curcp.ay + 1] && !board[curcp.bx][curcp.by + 1]) {
                param next = curcp;
                next.bx--;
                next.by++;
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
                next.ax++;
                next.bx++;                   
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
            }
        }
        else {
            if (0 <= curcp.ax - 1 && !board[curcp.ax-1][curcp.ay] && !board[curcp.bx-1][curcp.by]) {
                param next = curcp;
                next.bx--;
                next.by--;
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
                next.ay++;
                next.by++;
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
            }
            if (curcp.ax + 1 < n && !board[curcp.ax+1][curcp.ay] && !board[curcp.bx+1][curcp.by]) {
                param next = curcp;
                next.bx++;
                next.by--;
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
                next.ay++;
                next.by++;                
                if (cango(next, visit)) {
                    visit[getmyh(next)] = next.cnt;
                    q.push(next);
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> v(5);
    v[0] = { 0, 0, 0, 1, 1 };
    v[1] = { 0, 0, 0, 1, 0 };
    v[2] = { 0, 1, 0, 1, 1 };
    v[3] = { 1, 1, 0, 0, 1 };
    v[4] = { 0, 0, 0, 0, 0 };
    cout << solution(v);
    return 0;
}