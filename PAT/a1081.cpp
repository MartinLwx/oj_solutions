#include<bits/stdc++.h>
using namespace std;
long int a[101];
long int b[101];
long int gcd(long int a, long int b)
{
	if(b == 0)	return a;
	else return gcd(b, a%b);
}	//求最大公约数
void reduction(long int a[], long int b[], int i)
{
	int d = gcd(abs(a[i]), abs(b[i]));
	a[i] /= d;
	b[i] /= d;
}	//根据最大公约数化简分子分母
int main()
{
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%ld/%ld", &a[i], &b[i]);
		if(a[i] == 0)	b[i] = 1;	//为了不让求最大公约数出错，让实际为0的分数的分母弄为1——1和任何数的最大公约数都是1
		reduction(a, b, i);
	}
	a[0] = 0; b[0] = 1;   //对第i位的处理是让第i位和第i-1位来求和，所以让第0位表示为0
	for(int i=1;i<=n;i++)
	{
		long int gcd_value = gcd(b[i], b[i-1]);
		long int lcm_value = b[i] / gcd_value * b[i-1];		//先/后*减少溢出可能
		a[i-1] *= lcm_value / b[i-1];
		a[i] *= lcm_value /b[i];
		a[i] = a[i] + a[i-1];
		b[i] = lcm_value;
		reduction(a,b,i);
	}
	if(abs(a[n]) >= abs(b[n]))		//这里要用绝对值是因为会有负数的情况出现，比如-1/1
	{
		int t = a[n] / b[n];  
		int up = a[n] - t * b[n];
		if(up == 0)
			printf("%ld\n", t);
		else
			printf("%ld %ld/%ld\n", t, up, b[n]);
	}else
    {
        if(a[n] == 0)
            printf("0\n");		//这里不单独处理的话，是会输出0/n这种类型的数字的
        else
            printf("%ld/%ld\n", a[n], b[n]);
    }


	return 0;
}
