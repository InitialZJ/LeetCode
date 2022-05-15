#include<iostream>
#include<algorithm>
using namespace std;
const int N = 105;
int n, father[N], cnt, ans, x_father, y_father;
struct MyStruct
{
	int u, v, w;
}edge[N * (N - 1) / 2];
int read()
{
	int X = 0; bool flag = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') flag = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { X = (X << 1) + (X << 3) + ch - '0'; ch = getchar(); }
	if (flag) return X;
	return ~(X - 1);
}
bool cmp(struct MyStruct a, struct MyStruct b)
{
	return a.w < b.w;
}
int find(int x)
{
	if (father[x] == x)
		return x;
	return father[x] = find(father[x]);
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	int n;
	while (cin >> n && n)
	{
		cnt = ans = 0;
		for (int i = 1; i <= n; i++)
			father[i] = i;
		for (int i = 0; i < n * (n - 1) / 2; i++)
		{
			edge[i].u = read();
			edge[i].v = read();
			edge[i].w = read();
		}
		sort(edge, edge + n * (n - 1) / 2, cmp);
		for (int i = 0; i < n * (n - 1) / 2; i++)
		{
			x_father = find(edge[i].u);
			y_father = find(edge[i].v);
			if (x_father != y_father)
			{
				father[x_father] = y_father;
				ans += edge[i].w;
				cnt++;
				if (cnt == n - 1)
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}