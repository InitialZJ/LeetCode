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
		cout << n << "��" << m << "�����Լ��Ϊ��" << gcd(n, m) << endl;
		cout << n << "��" << m << "����С������Ϊ��" << n * m / gcd(n, m) << endl;
	}
	return 0;
}