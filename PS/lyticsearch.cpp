#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
private:
    Trie* child[26];
    int count;
public:
    Trie() : child(), count(0) {}
    void Insert(string str) {
        Trie* now = this;
        for (char ch : str) {
            now->count++;
            if (now->child[ch - 'a'] == nullptr) now->child[ch - 'a'] = new Trie();
            now = now->child[ch - 'a'];
        }
    }

    int Search(string str) {
        Trie* now = this;
        for (char ch : str) {
            if (ch == '?') return now->count;
            now = now->child[ch - 'a'];
            if (now == nullptr) break;
        }
        return 0;
    }
};

Trie TrieRoot[10001];
Trie ReTrieRoot[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (string str : words) {
        TrieRoot[str.length()].Insert(str);
        reverse(str.begin(), str.end());
        ReTrieRoot[str.length()].Insert(str);
    }
    for (string query : queries) {
        if (query[0] != '?') answer.push_back(TrieRoot[query.length()].Search(query));
        else {
            reverse(query.begin(), query.end());
            answer.push_back(ReTrieRoot[query.length()].Search(query));
        }
    }
    return answer;
}

int main() {
    vector<int> v = solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "fro??", "????o", "fr???", "fro???", "pro?" });
    for (int a : v) {
        cout << a << " ";
    }    
    return 0;
}