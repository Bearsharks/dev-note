#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Param {
public:
    pair<int, int> p;
    int cur;
    bool isFreeEmpty;
};

struct MyHash {
    size_t operator()(const Param& p) const {
        hash<int> hash_func; // string 을 파라미터로 받아 해시 함수값을 리턴해주는 C++ 제공 해시 객체

        return hash_func(p.p.first*10 + p.p.second) ^ hash_func(p.cur) ^ hash_func(p.isFreeEmpty); // 임의로 string 인 name 의 해시함수값과 int인 grade 값을 XOR 연산한 것을 해시 함수 값으로 하기로 정의!
    }
};


unordered_map<Param,int, MyHash> dp;
int n, fn;
int f(pair<int, int> p, int cur, bool isFreeEmpty) {
    if (cur == n) {//마지막이라면
        return (cur - 1 != fn && p.first) + (cur != fn && p.second) + isFreeEmpty;
    }
    Param param = { p,  cur, isFreeEmpty };
    if (dp.count(param) != 0) return dp[param];
    int ret = 0;
    if (cur == fn) {
        ret = f({ p.second,true }, cur + 1, isFreeEmpty);
    }
    else {
        if (p.first) {//왼쪽
            ret += f({ p.second,true }, cur + 1, (cur - 1 != fn) && isFreeEmpty);
        }
        if (p.second) {//중간
            ret += f({ p.second,true }, cur + 1, (cur != fn) && isFreeEmpty);
        }
        //오른쪽
        ret += f({ p.second,true }, cur + 1, (cur + 1 != fn) && isFreeEmpty);
        //왼 중 오 중에서 fn이 없었을때 자유석에 앉는 경우
        if (fn < cur - 1 && cur + 1 < fn && isFreeEmpty) {
            ret += f({ p.second,true }, cur + 1, false);
        }
    }
    dp[param] = ret;
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> fn;
    vector<int> v(n+1);
    cout << f({ false,true }, 1, true);

    return 0;
}