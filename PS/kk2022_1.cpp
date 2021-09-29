#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> m;
    for (int i = 0; i < report.size(); i++) {
        vector<string> re = split(report[i], ' ');
        m[re[0]].insert(re[1]);
    }
    map<string, int> reports;
    set<string> banned;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        for (auto siter = iter->second.begin(); siter != iter->second.end(); siter++) {
            reports[*siter]++;
        }
    }
    for (auto iter = reports.begin(); iter != reports.end(); iter++) {
        if (iter->second >= k) banned.insert(iter->first);
    }
    for (string id : id_list) {
        int cnt = 0;
        for (auto iter = m[id].begin(); iter != m[id].end(); iter++) {
            cnt += banned.count(*iter);
        }
        answer.push_back(cnt);
    }
    return answer;
}