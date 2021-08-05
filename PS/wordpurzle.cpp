#include <iostream>
#include <vector>
using namespace std;

const int MX = 20001;
class Trie;
string str;
Trie* root;
class Trie {
public:
    Trie* child[26] = { nullptr, };
    char alpha;
    int count;
    Trie(char a) : child(), count(0),alpha(a){}
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (child[i] != nullptr) delete child[i];
        }
    }
    void Insert(string str) {
        Trie* now = this;
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if (now->child[ch - 'a'] == nullptr) now->child[ch - 'a'] = new Trie(ch);            
            now = now->child[ch - 'a'];
        }
        now->count++;
    }

};

vector<int> v(MX, -1);

int dp(int idx){
    if (idx >= str.size()) return 0;
    int& ret = v[idx];
    if (ret != -1) return ret;
    ret = MX;
    Trie* cur = root->child[str[idx] - 'a'];
    int prog = 0;
    while (cur) {
        prog++;
        if (cur->count > 0) ret = min(1 + dp(idx + prog), ret);
        if (idx + prog >= str.size()) break;
        cur = cur->child[str[idx+prog] - 'a'];
    }    
    return ret;
}

int solution(vector<string> strs, string t)
{
    int answer = -1;
    str = t;
    root = new Trie(0);
    for (int i = 0; i < strs.size(); i++) {
        root->Insert(strs[i]);
    }
    answer = dp(0);
    delete root;
    return answer >= MX? -1 :answer;
}
int main() {
    cout << solution({ "ab", "na", "n", "a", "bn" }, "nabnabn");
    return 0;
}