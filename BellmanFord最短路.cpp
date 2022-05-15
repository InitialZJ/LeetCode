#include<iostream>
#include<memory.h>
using namespace std;
const int N = 105, M = 2e5 + 5, INF = 0x3f3f3f3f;
int n, m, dis[N], u[M], v[M], w[M], flag;
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (cin >> n >> m && !(n == 0 && m == 0))
	{
		for (int i = 0; i < m; i++)
			cin >> u[i] >> v[i] >> w[i];
		for (int i = m; i < 2 * m; i++)
		{
			u[i] = v[i - m];
			v[i] = u[i - m];
			w[i] = w[i - m];
		}
		memset(dis, INF, sizeof(dis));
		dis[1] = 0;
		for (int i = 1; i < n; i++)
		{
			flag = 1;
			for (int j = 0; j < 2 * m; j++)
				if (dis[v[j]] > dis[u[j]] + w[j])
				{
					dis[v[j]] = dis[u[j]] + w[j];
					flag = 0;
				}
			if (flag)
				break;
		}
		cout << dis[n] << endl;
	}
	return 0;
}