#include<iostream>
using namespace std;
int main() {
	int x[10000], y[10000];
	int n;
	while (~scanf("%d", &n) && n) {
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		double ans = 0.0;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		for (int i = 1; i < n; i++) {
			ans += 0.5 * (x[i] * y[i + 1] - x[i + 1] * y[i]);
		}
		ans += 0.5 * (x[n] * y[1] - x[1] * y[n]);
		printf("%.1f\n", ans);
	}
	return 0;
}