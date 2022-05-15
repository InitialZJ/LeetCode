#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, Hash[2 * N], tmp, cnt;
int gcd(int a, int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (~scanf("%d %d", &n, &m))
	{
		cout << n << "和" << m << "的最大公约数为：" << gcd(n, m) << endl;
		cout << n << "和" << m << "的最小公倍数为：" << n * m / gcd(n, m) << endl;
	}
	return 0;
}