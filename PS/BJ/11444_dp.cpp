#include <iostream>
#include <string>
#include <map>

using namespace std;
typedef unsigned long long ull;
const ull d = 1000000007;
pair<string,string> numSplit(string bignum) {
    int sum = 0;
    string ret;
    int remain = 0;
    for (int i = (bignum[0] == '0') ? 1 : 0 ; i < bignum.size(); i++) {
        int digit = (bignum[i] - '0');
        ret.push_back(remain + digit / 2 + '0');
        remain = (digit & 1) ? 5 : 0;
    }
    if (remain) {//È¦¼ö ¿´´Ù¸é inc ret
        string inc = ret;
        for (string::reverse_iterator ri = ret.rbegin(); ri != ret.rend(); ri++) {
            if (*ri < '9') {
                ++(*ri); break;
            }
            else {
                *ri = '0';
            }
        }
        return { inc,ret };
    }
    //Â¦¼ö¶ó¸é ret dec
    string dc = ret;
    for (string::reverse_iterator ri = dc.rbegin(); ri != dc.rend(); ri++) {
        if (*ri > '0') {
            --(*ri); break;
        }
        else {
            *ri = '9';
        }
    }
    return { ret,dc };
}
map<string, ull> m;
ull f(string num) {
    if (m.count(num)) return m[num];
    ull& ret = m[num];
    pair<string, string> p = numSplit(num);
    bool isodd = (num.back() - '0') & 1;
    ull one = f(p.first);
    ull two = f(p.second);
    if (isodd) {
        ret = (one * one + two * two) % d;
    }
    else {
        ret = ((one + two) * one + one * two) % d;
    }
    return ret;
}



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string n;
	cin >> n;
    m["0"] = 0;
    m["1"] = 1;
    m["2"] = 1;
    m["3"] = 2;
    m["4"] = 3;
    m["5"] = 5;
    cout << f(n);
	return 0;
}