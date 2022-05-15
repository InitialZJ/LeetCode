#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
const int N = 1e5 + 5;
int a, b, flag, father[N], a_father, b_father;
int find(int x)
{
	if (father[x] == x)
		return x;
	return father[x] = find(father[x]);
}
int main()
{
	//freopen("D:\\Data.txt", "r", stdin);
	scanf("%d %d", &a, &b);
	while (a != -1 && b != -1)
	{
		for (int i = 1; i < N; i++)
			father[i] = i;
		flag = 0;
		while (a && b)
		{
			a_father = find(a);
			b_father = find(b);
			if (a_father == b_father)
				flag = 1;
			else
				father[a_father] = b_father;
			scanf("%d %d", &a, &b);
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}