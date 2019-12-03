#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)	cin >> a[i];
	int remain = 0;
	for(int i=0;i<n;i++)
		if(a[i] != i && a[i] != 0)
			remain++;
	int k = 1;
	int ans = 0;
	while(remain > 0)
	{
		if(a[0] == 0)    //0在本位上
		{
			while(k < n)
			{
				if(a[k] != k)   //找到第一个不在该在的位置上的数字
				{
					swap(a[0], a[k]);
					ans++;
					break;
				}
				k++;
			}
		}

		while(a[0] != 0)    //当0不在0号位的时候
		{
			swap(a[0], a[a[0]]);   //将0所在位置上的数和0进行交换
			ans++;
			remain--;
		}
	}
	cout << ans;
	return 0;
}

