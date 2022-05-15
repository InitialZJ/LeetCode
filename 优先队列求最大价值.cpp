#include<iostream>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<stack>
using namespace std;
#define LL long long
const int N = 1e5 + 5, INF = 0x3f3f3f3f;
priority_queue<LL, vector<LL>, greater<LL>>qu;
LL n, ans = 0, t = 0;
struct Mystruct
{
	LL d, p;
}cow[N];
bool cmp(struct Mystruct a, struct Mystruct b)
{
	return a.d < b.d;
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cow[i].d >> cow[i].p;
	sort(cow, cow + n, cmp);
	for (int i = 0; i < n; i++)
	{
		ans += cow[i].p;
		t++;
		qu.push(cow[i].p);
		if (t > cow[i].d)
		{
			ans -= qu.top();
			qu.pop();
			t--;
		}
	}
	cout << ans << endl;
	return 0;
}