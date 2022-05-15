#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105;
const double eps = 1e-8;
int n, stack[N], top;
double ans;
struct Point
{
	double x, y;
}point[N];
double crossProduct(Point a, Point b)
{
	return a.x * b.y - b.x * a.y;
}
int sgn(double x)
{
	if (fabs(x) < eps)
		return 0;
	if (x < 0)
		return -1;
	else
		return 1;
}
Point sub(Point a, Point b)
{
	Point p;
	p.x = a.x - b.x;
	p.y = a.y - b.y;
	return p;
}
double dis(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp1(Point a, Point b)
{
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
		return a.y < b.y;
	return false;
}
bool cmp2(Point a, Point b)
{
	double tmp = crossProduct(sub(a, point[0]), sub(b, point[0]));
	if (sgn(tmp) > 0)
		return true;
	else if (sgn(tmp) == 0 && sgn(dis(a, point[0]) - dis(b, point[0])) <= 0)
		return true;
	else
		return false;
}
void graham_scan()
{
	sort(point, point + n, cmp1);
	sort(point + 1, point + n, cmp2);
	stack[0] = 0;
	if (n == 1)
	{
		top = 1;
		return;
	}
	stack[1] = 1;
	if (n == 2)
	{
		top = 2;
		return;
	}
	top = 2;
	for (int i = 2; i < n; i++)
	{
		while (top > 1 && sgn(crossProduct(sub(point[stack[top - 1]], point[stack[top - 2]]), sub(point[i], point[stack[top - 2]]))) < 0)
			top--;
		stack[top++] = i;
	}
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (cin >> n && n)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
			cin >> point[i].x >> point[i].y;
		graham_scan();
		stack[top++] = 0;
		for (int i = 0; i < top - 1; i++)
			ans += dis(point[stack[i]], point[stack[i + 1]]);
		if (n == 2)
			printf("%.2lf\n", ans / 2);
		else
			printf("%.2lf\n", ans);
	}
	return 0;
}