#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

tuple<string, int, int> getHeadNum(string& s, int i) {
    string head = "";
    int num = 0;
    bool isFoundHead = false;
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            num = num * 10 + c - '0';
            isFoundHead = true;
        }
        else {
            if (isFoundHead) break;
            if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
            head.push_back(c);
        }
    }
    return { head , num,i };
}
vector<string> solution(vector<string> files) {
    vector<string> answer(files.size());
    vector<tuple<string, int, int>> v;
    for (int i = 0; i < files.size(); i++) {
        v.push_back(getHeadNum(files[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        answer[i] = files[get<2>(v[i])];
    }
    return answer;
}
int main() {
    solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
    return 0;
}