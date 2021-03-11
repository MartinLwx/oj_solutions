#include<bits/stdc++.h>
using namespace std;
double a[100010];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}

	double ans = 0.0;
	for(int i=1;i<=n;i++)
	{
		ans += a[i]*i*(n-i+1);
	}
	printf("%.2lf", ans);
	return 0;
}

/*
<1,2,3,4,5> = 1, 12, 123, 1234, 12345, 
              2, 23, 234, 2345,
              3, 34, 345,
              4, 45,
              5
              = 1*5 + 2*8 + 3*9 + 4*8 + 5*5
              = 1*n + 2*((n-1)*2) + 3*((n-2)*3) + 4*((n-3)*4) + 5*((n-4)*5)  (n=5)
推导结果： a[i] * i * (n-i+1)
*/