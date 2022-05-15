#include<iostream>
using namespace std;
const int N = 505;
int k, m, n, nxt[N], a, b, ans;
bool map[N][N], vis[N];
bool find(int x)
{
	for (int i = 1; i <= n; i++)
		if (map[x][i] && !vis[i])
		{
			vis[i] = true;
			if (nxt[i] == 0 || find(nxt[i]))
			{
				nxt[i] = x;
				return true;
			}
		}
	return false;
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (cin >> k && k)
	{
		ans = 0;
		memset(map, false, sizeof(map));
		memset(nxt, 0, sizeof(nxt));
		cin >> m >> n;
		while (k--)
		{
			cin >> a >> b;
			map[a][b] = true;
		}
		for (int i = 1; i <= m; i++)
		{
			memset(vis, false, sizeof(vis));
			if (find(i))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}