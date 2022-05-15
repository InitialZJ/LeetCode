#include<iostream>
#include<string.h>
using namespace std;
const int N = 105, INF = 0x3f3f3f3f;
int n, graph[N][N], q, a, b, lowcost[N], ans = 0, minn, minid;
bool vis[N];
void prim()
{
	for (int i = 1; i < n; i++)
	{
		minn = INF;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && lowcost[j] < minn)
			{
				minn = lowcost[j];
				minid = j;
			}
		ans += minn;
		vis[minid] = true;
		for (int j = 1; j <= n; j++)
			if (graph[minid][j] < lowcost[j])
				lowcost[j] = graph[minid][j];
	}
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	memset(vis, false, sizeof(vis));
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> graph[i][j];
	a = 1;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 0;
	}
	vis[a] = true;
	for (int i = 1; i <= n; i++)
		lowcost[i] = graph[a][i];
	prim();
	cout << ans << endl;
	return 0;
}