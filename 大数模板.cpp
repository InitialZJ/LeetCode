#include <iostream>
#include<algorithm>
using namespace std;
const int MAXN = 100;
int s[MAXN], spt[MAXN], len = 1;
void Add(int a[], int la, int b[], int lb) {
	int c = 0;
	len = max(la, lb);
	for (int i = 0; i < len; i++) {
		a[i] += b[i] + c;
		c = a[i] / 10;
		a[i] %= 10;
	}
	if (c)
		a[len++] = c;
}
int main() {
	int n, t = 1, c = 0;
	scanf("%d", &n);
	s[0] = spt[0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < t; j++) {
			s[j] = s[j] * i + c;
			c = s[j] / 10;
			s[j] %= 10;
		}
		while (c) {
			s[t++] = c % 10;
			c /= 10;
		}
		Add(spt, len, s, t);
	}
	for (int i = len - 1; i >= 0; i--)
		printf("%d", spt[i]);
	printf("\n");
	return 0;
}