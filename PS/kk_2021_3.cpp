#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

bool dec(int& a, int& b) {
    return a > b;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<int, vector<int>> test;
    for (int i = 0; i < info.size(); i++) {
        istringstream istr(info[i]);
        string lang, kind, career, soul;
        pair<int, int> p;
        istr >> lang >> kind >> career >> soul >> p.second;
        if (lang[0] == 'j') p.first += 1;
        else if (lang[0] == 'p') p.first += 2;
        if (kind[0] == 'b') p.first += 1 << 2;
        if (career[0] == 'j') p.first += 1 << 3;
        if (soul[0] == 'c') p.first += 1 << 4;
        test[p.first].push_back(p.second);
    }
    for (int i = 0; i < query.size(); i++) {
        istringstream istr(query[i]);
        string lang, kind, career, soul;
        string tmp;
        pair<int, int> p;
        istr >> lang >> tmp >> kind >> tmp >> career >> tmp >> soul >> p.second;
        if (lang[0] == 'j') p.first += 1;
        else if (lang[0] == 'p') p.first += 2;
        if (kind[0] == 'b') p.first += 1 << 2;
        if (career[0] == 'j') p.first += 1 << 3;
        if (soul[0] == 'c') p.first += 1 << 4;
        int cnt = 0;
        for (int score : test[p.first]) {
            if (score >= p.second) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main() {
    vector<string> orders = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> course = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> res = solution(orders, course);

    return 0;
}