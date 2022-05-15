#include<iostream>
using namespace std;
const int N = 105;
int n, ans;
struct MyStruct
{
	double x1, y1, x2, y2;
}line[N];
bool intersection(struct MyStruct l1, struct MyStruct l2)
{
	//快速排斥实验
	if ((l1.x1 > l1.x2 ? l1.x1 : l1.x2) < (l2.x1 < l2.x2 ? l2.x1 : l2.x2) ||
		(l1.y1 > l1.y2 ? l1.y1 : l1.y2) < (l2.y1 < l2.y2 ? l2.y1 : l2.y2) ||
		(l2.x1 > l2.x2 ? l2.x1 : l2.x2) < (l1.x1 < l1.x2 ? l1.x1 : l1.x2) ||
		(l2.y1 > l2.y2 ? l2.y1 : l2.y2) < (l1.y1 < l1.y2 ? l1.y1 : l1.y2))
		return false;
	//跨立实验
	if ((((l1.x1 - l2.x1) * (l2.y2 - l2.y1) - (l1.y1 - l2.y1) * (l2.x2 - l2.x1)) *
		((l1.x2 - l2.x1) * (l2.y2 - l2.y1) - (l1.y2 - l2.y1) * (l2.x2 - l2.x1))) > 0 ||
		(((l2.x1 - l1.x1) * (l1.y2 - l1.y1) - (l2.y1 - l1.y1) * (l1.x2 - l1.x1)) *
		((l2.x2 - l1.x1) * (l1.y2 - l1.y1) - (l2.y2 - l1.y1) * (l1.x2 - l1.x1))) > 0)
		return false;
	return true;
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (cin >> n && n)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
			cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (intersection(line[i], line[j]))
					ans++;
		cout << ans << endl;
	}
	return 0;
}