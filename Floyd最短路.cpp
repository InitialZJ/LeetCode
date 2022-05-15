#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
const int N = 205, INF = 0x3f3f3f3f;
int dp[N][N], n, m, s, t, x, y, z;
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (~scanf("%d %d", &n, &m))
	{
		memset(dp, INF, sizeof(dp));
		for (int i = 0; i < n; i++)
			dp[i][i] = 0;
		while (m--)
		{
			cin >> x >> y >> z;
			dp[y][x] = dp[x][y] = min(dp[x][y], z);
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		cin >> s >> t;
		if (dp[s][t] == INF)
			cout << -1 << endl;
		else
			cout << dp[s][t] << endl;
	}
	return 0;
}