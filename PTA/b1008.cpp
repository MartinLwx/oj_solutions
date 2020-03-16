#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int real = m % n; //转换为单个数组的移动
	int mid = n / 2;
	if (real > mid)   //向左移
	{
		int cnt = n - real;
		for (int i = cnt; i < n; ++i)
		{
			swap(a[i], a[i-cnt]);
		}
	}else
	{
		int cnt = n - 1 - real;
		for (int i = cnt; i >= 0; i--)
		{
			swap(a[i], a[i+real]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i != n-1)
			cout << a[i] << " ";
		else
			cout << a[i];
	}
    return 0;
}
