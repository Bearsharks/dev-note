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
        hash<int> hash_func; // string �� �Ķ���ͷ� �޾� �ؽ� �Լ����� �������ִ� C++ ���� �ؽ� ��ü

        return hash_func(p.p.first*10 + p.p.second) ^ hash_func(p.cur) ^ hash_func(p.isFreeEmpty); // ���Ƿ� string �� name �� �ؽ��Լ����� int�� grade ���� XOR ������ ���� �ؽ� �Լ� ������ �ϱ�� ����!
    }
};


unordered_map<Param,int, MyHash> dp;
int n, fn;
int f(pair<int, int> p, int cur, bool isFreeEmpty) {
    if (cur == n) {//�������̶��
        return (cur - 1 != fn && p.first) + (cur != fn && p.second) + isFreeEmpty;
    }
    Param param = { p,  cur, isFreeEmpty };
    if (dp.count(param) != 0) return dp[param];
    int ret = 0;
    if (cur == fn) {
        ret = f({ p.second,true }, cur + 1, isFreeEmpty);
    }
    else {
        if (p.first) {//����
            ret += f({ p.second,true }, cur + 1, (cur - 1 != fn) && isFreeEmpty);
        }
        if (p.second) {//�߰�
            ret += f({ p.second,true }, cur + 1, (cur != fn) && isFreeEmpty);
        }
        //������
        ret += f({ p.second,true }, cur + 1, (cur + 1 != fn) && isFreeEmpty);
        //�� �� �� �߿��� fn�� �������� �������� �ɴ� ���
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