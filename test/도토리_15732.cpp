#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


// ���� �̺�Ž���� ���̴�.
// ������ �������� �Դ� ���� �� ���ΰ�?
// ���ϴ� ���� ���丮 ������ ���� ���̴�?
// ���̿� �ִ� ���丮 ������ ���� ���̴�.
// ���丮�� ó�����ں��� ä�������̴�?
// ������ ���ڰ� ���������� �Դ� �����ϸ鼭 ã�� ���̴�.
// ���丮�� ���� �ʾ��� �� �� ���� ���� ���� ���̴�.
// ������ ���丮 ���� ���ϱ� �ƹ�ư �������� ���� ���� 1
// �װ� m��ŭ �ݺ� m, log n * m�� �ð� ���⵵�� ���´�.
// ���ۻ��ں��� mid�� �۾��� �� ������ ��
// 10�� ���ϰ� ������ ���丮�� ���� �� �� int�� ���
inline int calcDoto(int s, int e, int interval) {
    return (e - s) / interval + 1;
}

bool isRemainDoto(vector<tuple<int, int, int>>& v, int mid, int d) {
    int cnt = 0;
    for (tuple<int, int, int >& t : v) {
        int s = get<0>(t);
        if (s > mid) continue; // �ε� ���Ǹ� ���ؼ� �ѹ� Ʋ��
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
    while (l < r) {// ���Ϸ��� ���� ���丮�� �� �������� �� �� ���� ���� ��
        // ���丮�� �� �ʿ��ϸ� ���δ�. r = mid - 1
        // ���丮�� ������ �ø���. l = mid + 1
        int mid = (r + l) / 2;
         if (isRemainDoto(v, mid, d)) { // ������ �ø���.
            l = mid + 1;
        }
        else { // �����ϰų� ������ ���ϼ���?
            r = mid;
        }
    }

    cout << r;
 
    return 0;
}