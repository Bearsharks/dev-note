#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> keys;
bool isUnique(int k) {
    for (int i = 0; i < keys.size(); i++) {
        if ((keys[i] & k) == keys[i])	
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int n = relation[0].size();
    int noftuple = relation.size();
    for (int i = 1; i <= (1 << (n - 1)); i++) {
        if (isUnique(i)) {
            int bitmap = i;
            int idx = 0;
            vector<int> selectedAttr;
            while (bitmap) {
                if (bitmap & 1) {
                    selectedAttr.push_back(idx);
                }
                bitmap /= 2;
                idx++;
            }
            set<string> s;
            for (vector<string>& v : relation) {
                string tuple = "";
                for (int i : selectedAttr) {
                    tuple += v[i];
                }
                s.insert(tuple);
            }
            if (s.size() == noftuple) keys.push_back(i);
        }
    }
    return keys.size();;
}
int main() {
    solution({{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}} );
    return 0;
}