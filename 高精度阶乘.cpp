#include <iostream>
#include<memory.h>
using namespace std;
int n, arr[10000] = { 0 }, brr[10000] = { 0 };
int main()
{
	cin >> n;
	int count1 = 1, count2 = 1; ///count1Ϊ�׳�����λ����count2Ϊ�������λ��;
	memset(arr, 0, sizeof(arr));
	memset(brr, 0, sizeof(brr));
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		///�׳�
		for (int j = 0; j < count1; j++)
		{
			arr[j] *= i;
		}
		for (int j = 0; j < count1; j++)
		{
			if (arr[j] >= 10)
			{
				arr[j + 1] += arr[j] / 10;
				arr[j] %= 10;
			}
		}
		while (arr[count1])
		{
			arr[count1 + 1] += arr[count1] / 10;
			arr[count1] %= 10;
			count1++;
		}
		///plus
		count2 = count1;
		for (int i = 0; i < count1; i++)
		{
			brr[i] += arr[i];
			if (brr[i] >= 10)
			{
				brr[i + 1] += brr[i] / 10;
				brr[i] %= 10;
			}
		}
		while (brr[count2])
		{
			brr[count2 + 1] += brr[count2] / 10;
			brr[count2] %= 10;
			count2++;
		}
	}
	for (int i = count2 + 1; i >= 0; i--) ///���
	{
		if (brr[i] != 0)
		{
			for (int j = i; j >= 0; j--)
				cout << brr[j];
			cout << endl;
			break;
		}
	}
	return 0;
}