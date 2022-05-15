#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
const int N = 1005;
int n, q, s, d, now;
double map[N][N], safe[N];
bool vis[N];
void spfa()
{
	queue<int>qu;
	memset(safe, 0, sizeof(safe));
	memset(vis, false, sizeof(vis));
	vis[s] = true;
	safe[s] = 1;
	qu.push(s);
	while (!qu.empty())
	{
		now = qu.front();
		qu.pop();
		vis[now] = false;
		for (int i = 1; i <= n; i++)
			if (map[now][i] > 0 && safe[i] < safe[now] * map[now][i])
			{
				safe[i] = safe[now] * map[now][i];
				if (!vis[i])
				{
					vis[i] = true;
					qu.push(i);
				}
			}
	}
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%lf", &map[i][j]);
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d %d", &s, &d);
			spfa();
			if (safe[d] == 0)
				cout << "What a pity!" << endl;
			else
				printf("%.3lf\n", safe[d]);
		}
	}
	return 0;
}