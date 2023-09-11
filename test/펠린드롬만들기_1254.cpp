#include <iostream>
#include <string>
using namespace std;
// ���� 50���� �ƹ��ų� �ص���
// �縰����� ����� �Ȱ��� ���̴ϱ� ����� �����غ���
// �ʿ��� ���� �߰��� �ʿ��� ���� � ���¿��� �߰��� �ʿ��� ����? 
// �������� �ٸ� ������ŭ �߰��� �ʿ��Ѱ���
// ��ü ���� + �߰����� = ��
int compareWithReversed(const string& str) {
    int length = str.size();
    for (int i = 0; i < length; ++i) {
        bool isSame = true;
        for (int j = i, k = 0; j < length; ++j, ++k) {
            if (str[j] != str[length - k - 1]) {
                isSame = false;
                break;
            }
        }
        if (isSame) {
            return i;
        }
    }
    return length;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    cout << a.size() + compareWithReversed(a) << "\n";

    return 0;
}
