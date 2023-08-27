#include <iostream>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

/* ���� 
4000 * 4000�� ��� ������ �����ΰ� ������ ���� ������ ����. 16,000,000�� 
���� ����� õ���� �ؽü¿� ������ ��û �����ɸ��� �� �ȵǴ���
���� ���� 2000�� �ε� �׷��� 16,000,000,000 �޸𸮵� �ʿ��ϴ�
�����ϰ��ϱ�� �ȵ�

Ʈ���̸� �Ẹ��
����� �г��� Ʈ���̸� �����ΰ�, ���� �߰� �� �г���Ʈ���̷� �Űܰ��� Ž���� �����Ѵ�?
���̸� 2000�ڴϱ� �պκк��� �ϳ��� Ž���Ҷ� ���� �׻� �ִ� �����̸� �г��� Ž���� 999 998 997... ��ŭ �ɸ� ��
n*n �̰� �־��� ��� 4,000,000 * q(20000) �ƹ�ư �ȵ�

���� Ʈ���̸� Ȱ�� �г����� �ؽ���Ȱ��
���̸� 2000�ڴϱ� �տ������� ���� �� �׻� ������ �����Ѵٰ� �ϸ�
������ 1000�ڴϱ�
���� Ž�� * �ؽ���Ž�� * q(20000)
1000 * 1(�̷л�) * 20000 �̴ϱ� 20,000,000 ��õ�� �ð��� �ʿ��� �����

���ڿ� �ٷ�� �����ϱ� ����(�տ��� ���� Ž���ϸ� ���� < ���̸� ����Ʈ�� ��ӽ��������)
���̸��� ������ �ڿ��� pop_back�ϸ鼭 �ϸ� ������ ���� ��
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

/* Ʋ��
reserve�� algorithm�� ����ִ�.

�޸� �ʰ� ��
���� trie�� �迭�� �����ϸ�
1000�ڴϱ� 
������ 26^1000 ��ŭ ���.
4000��忡 213����Ʈ 852 MB�� ��ٰ� �Ѵ�.

map���� �ٲٴ� �ذ��� �Ǿ���. �׷��� �޸� ����� ���� �ȵȴ�.

*/