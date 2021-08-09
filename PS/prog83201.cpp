#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
using namespace std;

char getGrade(double a) {
    char res = 'F';
    if (a >= 90) res = 'A';
    else if (a >= 80) res = 'B';
    else if (a >= 70) res = 'C';
    else if (a >= 50) res = 'D';
    return res;

}

string solution(vector<vector<int>> scores) {
    stringstream answer;
    int n = scores.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(scores[i][j], scores[j][i]);
        }
    }
    int stu = 0;
    for (vector<int>& curStuScores : scores) {
        swap(curStuScores[stu++], curStuScores.back());
        int scoreSelf = curStuScores.back(); curStuScores.pop_back();
        sort(curStuScores.begin(), curStuScores.end());
        if (curStuScores[0] <= scoreSelf && scoreSelf <= curStuScores.back()) {
            curStuScores.push_back(scoreSelf);
        }
        double aver = accumulate(curStuScores.begin(), curStuScores.end(),0) * 1.0 / curStuScores.size();
        answer << getGrade(aver);
        cout << aver << "\n";
    }
    return answer.str();
}
int main() {
    cout << solution({ { 100, 90, 98, 88, 65},{50, 45, 99, 85, 77},{47, 88, 95, 80, 67},{61, 57, 100, 80, 65},{24, 90, 94, 75, 65 } });
    return 0;
}