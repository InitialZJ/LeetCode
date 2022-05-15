#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
int t, n, v, val[N] = { 0 }, vol[N] = { 0 }, dp[N];
int main()
{
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n >> v;
		for (int i = 1; i <= n; i++)
			cin >> val[i];
		for (int i = 1; i <= n; i++)
			cin >> vol[i];
		for (int i = 1; i <= n; i++)
			for (int j = v; j >= vol[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - vol[i]] + val[i]);
			}
		cout << dp[v] << endl;
	}
	return 0;
}