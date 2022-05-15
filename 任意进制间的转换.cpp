#include<iostream>
#include<string>
using namespace std;
char str[100] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", ans[1000];
int n, k, cnt;
int main()
{
	while (cin >> n >> k)
	{
		cnt = 0;
		while (n)
		{
			ans[cnt++] = str[n % k];
			n /= k;
		}
		for (int i = cnt - 1; i >= 0; i--)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}