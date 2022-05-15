#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 1005, INF = 0x3f3f3f3f;
struct MyStruct
{
	int di, co;
}map[N][N];
int n, m, a, b, d, p, s, t, dis[N], cost[N], minn, tmp;
bool vis[N];
void dijkstra()
{
	vis[s] = true;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = map[s][i].di;
		cost[i] = map[s][i].co;
	}
	for (int i = 1; i < n; i++)
	{
		minn = INF;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < minn)
			{
				minn = dis[j];
				tmp = j;
			}
		vis[tmp] = true;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (map[tmp][j].di + dis[tmp] < dis[j]))
			{
				dis[j] = map[tmp][j].di + dis[tmp];
				cost[j] = map[tmp][j].co + cost[tmp];
			}
			else if (!vis[j] && (map[tmp][j].di + dis[tmp] == dis[j]))
				if (map[tmp][j].co + cost[tmp] < cost[j])
					cost[j] = map[tmp][j].co + cost[tmp];
	}
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (~scanf("%d%d", &n, &m), m + n)
	{
		memset(vis, false, sizeof(vis));
		memset(dis, INF, sizeof(dis));
		memset(cost, INF, sizeof(cost));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					map[i][j].di = map[i][j].co = 0;
				else
					map[i][j].di = map[i][j].co = INF;
		while (m--)
		{
			scanf("%d%d%d%d", &a, &b, &d, &p);
			if (d < map[a][b].di)
			{
				map[a][b].di = map[b][a].di = d;
				map[a][b].co = map[b][a].co = p;
			}
		}
		cin >> s >> t;
		dijkstra();
		cout << dis[t] << " " << cost[t] << endl;
	}
	return 0;
}