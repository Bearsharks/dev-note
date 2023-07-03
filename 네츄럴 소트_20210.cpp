#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

int compareBigDecimal(std::string num1, std::string num2) {
    int len1 = num1.length();
    int len2 = num2.length();

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;
    for (int i = 0; i < len1; i++) {
        if (num1[i] > num2[i])
            return 1;
        if (num1[i] < num2[i])
            return -1;
    }
    return 0;
}

string getCurrent(string::iterator& iter, string::iterator last) {
    string result = "";
    result.push_back(*iter++);
    if (!isNumber(result[0])) {
        return result;
    }
    while (iter != last && isNumber(*iter)) {
        result.push_back(*iter);
        iter++;
    }
    return result;
}

string trim(string& str) {
    int idx = 0;
    while (str[idx] == '0') {
        idx++;
    }
    if (idx >= str.size()) return "0";
    return str.substr(idx, str.size() - idx);
}

bool aisLess(string& a, string& b) {
    auto aiter = a.begin();
    auto biter = b.begin();
    while (aiter != a.end()) {
        // b가 더 이상 없으면 a가 더 큼
        if (biter == b.end()) return false;

        string cura = getCurrent(aiter, a.end());
        string curb = getCurrent(biter, b.end());
        if (cura == curb) continue;
        bool isAnumber = isNumber(cura[0]);
        bool isBnumber = isNumber(curb[0]);
        
        // 둘다 알파벳 일 때,
        if (!isAnumber && !isBnumber) {
            bool isAupper = cura[0] <= 'Z';
            bool isBupper = curb[0] <= 'Z';
            int isAOrder = isAupper ? cura[0] - 'A' : cura[0] - 'a';
            int isBOrder = isBupper ? curb[0] - 'A' : curb[0] - 'a';
            if (isAOrder == isBOrder) { // 같은 알파벳일때, a가 대문자면 a가 더 작다.
                return isAupper;
            }
            
            return isAOrder < isBOrder;
        }
        if (isAnumber && !isBnumber) return true;
        if (isBnumber && !isAnumber) return false; // b만 숫자면 a가 더 큼
        // 둘다 숫자 일 때,
        if (isAnumber && isBnumber) {
            string numbera = trim(cura);
            string numberb = trim(curb);
            int res = compareBigDecimal(numbera, numberb);
            if (res == 0) return cura.size() < curb.size();
            return res < 0;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), aisLess);
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}