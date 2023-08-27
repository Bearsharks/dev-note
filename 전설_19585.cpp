#include <iostream>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

/* 전략 
4000 * 4000의 모든 조합을 만들어두고 참조할 수는 없을것 같다. 16,000,000개 
저번 경험상 천만개 해시셋에 넣으면 엄청 오래걸리고 잘 안되더라
둘이 합쳐 2000자 인데 그러면 16,000,000,000 메모리도 필요하다
무식하게하기는 안됨

트라이를 써보자
색깔과 닉네임 트라이를 만들어두고, 색깔 발견 시 닉네임트라이로 옮겨가서 탐색을 수행한다?
팀이름 2000자니까 앞부분부터 하나씩 탐색할때 마다 항상 있는 색깔이면 닉네임 탐색은 999 998 997... 만큼 걸릴 것
n*n 이고 최악의 경우 4,000,000 * q(20000) 아무튼 안됨

색깔 트라이만 활용 닉네임은 해쉬셋활용
팀이름 2000자니까 앞에서부터 읽을 때 항상 색깔이 존재한다고 하면
색깔은 1000자니까
색깔 탐색 * 해쉬셋탐색 * q(20000)
1000 * 1(이론상) * 20000 이니까 20,000,000 이천만 시간이 필요함 충분함

문자열 다루기 쉽게하기 위해(앞에서 부터 탐색하면 색깔 < 팀이름 시프트를 계속시켜줘야함)
팀이름을 뒤집고 뒤에서 pop_back하면서 하면 구현이 쉬울 것
*/
class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    static TrieNode* findChildNode(TrieNode* node, char ch) {
        return node->children[ch];
    }

    void insert(std::string word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children[ch] == nullptr) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }
};

bool isLegend(Trie& colorTrie, unordered_set<string>& ts, string team) {
    TrieNode* curnode = colorTrie.root;
    while (team.size() > 0) {
        char c = team.back(); team.pop_back();
        curnode = colorTrie.findChildNode(curnode, c);
        if (curnode == nullptr) return false;
        if (curnode->isEndOfWord && ts.count(team)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int c, n;
    cin >> c >> n;
    Trie colorTrie;
    unordered_set<string> ts;
    for (int i = 0; i < c; i++) {
        string a;
        cin >> a;
        colorTrie.insert(a);
    }

    for (int i = 0; i < n; i++) {
        string nn;
        cin >> nn;
        reverse(nn.begin(), nn.end());
        ts.insert(nn);
    }

    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string team;
        cin >> team;
        reverse(team.begin(), team.end());
        cout << (isLegend(colorTrie, ts, team) ? "Yes\n" : "No\n");        
    }

    return 0;
}

/* 틀림
reserve는 algorithm에 들어있다.

메모리 초과 됨
색깔 trie를 배열로 구현하면
1000자니까 
꽉차면 26^1000 만큼 든다.
4000노드에 213바이트 852 MB가 든다고 한다.

map으로 바꾸니 해결이 되었다. 그런데 메모리 계산은 딱히 안된다.

*/