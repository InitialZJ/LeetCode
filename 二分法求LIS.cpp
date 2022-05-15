#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int N = 1e5 + 5;
LL a[N];
int n, dp[N], len, l, r, mid;
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	while (cin >> n)
	{
		len = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		dp[len] = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] > dp[len])
			{
				len++;
				dp[len] = a[i];
			}
			else
			{
				l = 0, r = len;
				while (r >= l)
				{
					mid = (l + r) / 2;
					if (dp[mid] < a[i])
						l = mid + 1;
					else
						r = mid - 1;
				}
				dp[l] = a[i];
			}
		}
		cout << len + 1 << endl;
	}
	return 0;
}