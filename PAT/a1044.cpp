#include<bits/stdc++.h>
using namespace std;
int sum[100010];

int find_upper_bound(int l, int r, int x)
{
	int left = l, right = r, mid;
	while(left < right)
	{
		mid = (left + right) >> 1;
		if(sum[mid] > x)  //和超过了x，但是我们此时仍旧没有排除这个位置，因为我们要找的是第一个大于x的位置
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}
int main()
{
	int n, m;
	cin >> n >> m;

	sum[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> sum[i];
		sum[i] += sum[i-1];
	}  //读取数据，记录子序列和，其中sum[i]表示a[1]~a[i]的和

	int nearest = 2100000000;
	//找最接近的情况
	for(int i=1;i<=n;i++)
	{
		int j = find_upper_bound(i, n+1, sum[i-1] + m);
		if(sum[j-1] - sum[i-1] == m)
		{
			nearest = m;   //最接近的就是m了，也就是说存在连续子序列和为m
			break;
		}else if (j <= n &&  sum[j] - sum[i-1] < nearest)
			nearest = sum[j] - sum[i-1]; //记录最接近的情况
	}
	for(int i=1;i<=n;i++)
	{
        //当nearest为m的时候，回按照i的递增顺序打印出所有答案，如果不是那么只打印出最接近的答案
		int j = find_upper_bound(i, n+1, sum[i-1] + nearest);
		if(sum[j-1] - sum[i-1] == nearest)
			cout << i << '-' << j-1 << endl;
	}
	return 0;
}