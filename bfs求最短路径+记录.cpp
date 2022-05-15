#include<iostream>
#include<queue>
#include<stack>
#include<memory.h>
using namespace std;
struct pot
{
	int a;
	int b;
	int step;
	int flag;
	pot* pre;
};
pot* now;
pot dire;
int am, bm, c, ans;
bool vis[120][120];
queue<pot>qu;
stack<int>st;
void bfs()
{
	memset(vis, false, sizeof(vis));
	now = new pot;
	now->a = now->b = now->step = now->flag = 0;
	now->pre = NULL;
	vis[now->a][now->b] = true;
	qu.push(*now);
	while (!qu.empty())
	{
		now = new pot;
		*now = qu.front();
		qu.pop();
		for (int i = 1; i <= 6; i++)
		{
			dire.flag = i;
			if (i == 1)
			{
				dire.a = am;
				dire.b = now->b;
			}
			if (i == 2)
			{
				dire.a = now->a;
				dire.b = bm;
			}
			if (i == 3)
			{
				dire.a = 0;
				dire.b = now->b;
			}
			if (i == 4)
			{
				dire.a = now->a;
				dire.b = 0;
			}
			if (i == 5)
			{
				dire.a = now->a;
				dire.b = now->b;
				while (dire.a != 0 && dire.b != bm)
				{
					dire.a--;
					dire.b++;
				}
			}
			if (i == 6)
			{
				dire.a = now->a;
				dire.b = now->b;
				while (dire.a != am && dire.b != 0)
				{
					dire.a++;
					dire.b--;
				}
			}
			if (!vis[dire.a][dire.b])
			{
				vis[dire.a][dire.b] = true;
				dire.step = now->step + 1;
				dire.pre = now;
				if (dire.a == c || dire.b == c)
				{
					ans = dire.step;
					while (dire.pre)
					{
						st.push(dire.flag);
						dire = *dire.pre;
					}
					return;
				}
				qu.push(dire);
			}
		}
	}
}
void print()
{
	while (!st.empty())
	{
		int i = st.top();
		st.pop();
		switch (i)
		{
		case 1:cout << "FILL(1)" << endl; break;
		case 2:cout << "FILL(2)" << endl; break;
		case 3:cout << "DROP(1)" << endl; break;
		case 4:cout << "DROP(2)" << endl; break;
		case 5:cout << "POUR(1,2)" << endl; break;
		case 6:cout << "POUR(2,1)" << endl; break;
		}
	}
}
int main()
{
	cin >> am >> bm >> c;
	ans = 0;
	bfs();
	if (ans == 0)
		cout << "impossible" << endl;
	else
	{
		cout << ans << endl;
		print();
	}
	return 0;
}