#include<bits/stdc++.h>
using namespace std;
int a[100010] = {0};
int length[100010] = {0};
int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		length[i] = sum;
	}
	int m;
	scanf("%d", &m);
	int l, r;
	int t; //暂时存储距离
	while(m--)
	{
		scanf("%d %d", &l, &r);
		if(l > r)	swap(l, r);
		t = length[r-1] - length[l-1];
		printf("%d\n", min(t, sum - t));
	}
	return 0;
}
