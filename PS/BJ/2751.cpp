#include <cstdio>

using namespace std;

int table[2000001] = { 0, };
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		table[a + 1000000]++;
	}
	for (int i = 0; i < 2000001; ++i) {
		if (table[i]) {
			printf("%d\n", i - 1000000);
		}
	}
	return 0;
}