#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v[a] = i;
    }//자동으로 정렬되고

    vector<int> ans = { -1,INT_MAX };
    //longest increasing subsequence를 구한다.
    for (int i = 1; i <= n; i++) {
        int min = 0;
        int max = ans.size()-1;
        while (min < max) {
            int mid = (min + max) / 2;
            
            if (ans[mid] < v[i]) {
                min = mid + 1;
            }
            else if (ans[mid] > v[i])  {
                max = mid;
            }
            else {
                break;
            }
        }
        if (max == ans.size() - 1) {
            ans.push_back(INT_MAX);
        }
        ans[max] = v[i];
    }
    cout << ans.size() - 2;

	return 0;
}

