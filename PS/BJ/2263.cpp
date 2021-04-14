#include <iostream>
#include <vector>
using namespace std;


vector<int> in(100000);
vector<int> post(100000);
void f(int inl, int inr, int postl, int postr) {
    cout << post[postr] << " ";
    int root = -1;    
    for (int i = inl; i <= inr; i++) {
        if (in[i] == post[postr]) {
            root = i;
            break;
        }
    }
    int leftsize = root - inl;
    if (leftsize) f(inl, root - 1, postl, leftsize + postl - 1);
    int rightsize = inr - root;
    if (rightsize) f(root + 1, inr, leftsize + postl, postr - 1);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }
    f(0, n - 1, 0, n - 1);

    return 0;
}
