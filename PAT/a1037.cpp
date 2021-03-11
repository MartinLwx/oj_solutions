#include<bits/stdc++.h>
using namespace std;
int a[100010];
int b[100010];


int main()
{
	int nc,np;
	scanf("%d", &nc);
	for(int i=0;i<nc;i++)	scanf("%d", &a[i]);
	scanf("%d", &np);
	for(int i=0;i<np;i++)	scanf("%d", &b[i]);
	sort(a, a+nc);
	sort(b, b+np);

	int p1 = 0;
	int p2 = 0;
	long long  ans = 0;

	while(p1 < nc && p1 < np && a[p1] < 0 && b[p1] < 0)    //处理负数和负数相乘的情况
	{
		ans += a[p1] * b[p1];
		p1++;
	}
	p1 = nc - 1;
	p2 = np - 1;
	while(p1 >= 0 && p2 >= 0 && a[p1] > 0 && b[p2] > 0)
	{
		ans += a[p1] * b[p2];
		p1--;
		p2--;
	}

	printf("%lld\n", ans);
	return 0;
}

