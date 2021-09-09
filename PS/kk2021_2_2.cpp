#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> getCourses(string str) {
    vector<string> result = { "" };
    for (int i = 0; i < str.size(); i++) {
        int curN = result.size();
        char curMenu = str[i];
        for (int j = 0; j < curN; j++) {
            string newCourse = result[j];
            newCourse.push_back(curMenu);
            result.push_back(newCourse);
        }
    }
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<map<string, int>> candis(11);
    //���ο� �ڽ� ������ ��� ���ؼ� �� �޴� �������� �з��ؼ� �ĺ��� �������
    //�ĺ��� ���� �ֹ� Ƚ���� candis�� ��� �ְ� �ȴ�.
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        vector<string> newCourses = getCourses(orders[i]);
        for (string newCourse : newCourses) {
            candis[newCourse.size()][newCourse]++;
        }
    }
    //���ؾ��ϴ� �޴� �������� ���� ���� �ֹ��ߴ� �ڽ��� answer�� ��´�.
    for (int n : course) {
        vector<string> bestCourses;
        int mx = 0;
        for (map<string, int>::iterator iter = candis[n].begin(); iter != candis[n].end(); iter++) {
            if (mx < iter->second) {
                bestCourses.clear();
                bestCourses.push_back(iter->first);
                mx = iter->second;
            }
            else if (mx == iter->second) {
                bestCourses.push_back(iter->first);
            }
        }
        if (mx >= 2) {
            for (string bestCourse : bestCourses) {
                answer.push_back(bestCourse);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}