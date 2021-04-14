#include <iostream>
#include "DS/HashMapTrie.h"
#include <unordered_map>
using namespace std;


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    HashMap<string, int> m;
    //unordered_map<string, int> m;
    for (int i = 0; i < 1000000; i++) {
        string test = "";
        int k = i;
        test += 'a' + k % 26;
        k /= 26;
        while (k) {
            test += 'a' + k % 26;
            k /= 26;
        }

        m.set(test,i);
        k = m.get(test);

    }
    return 0;
}
