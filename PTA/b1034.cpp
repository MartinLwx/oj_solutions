#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	if(b == 0)	return a;
	else return gcd(b, a%b);
}	//求最大公约数

void reduction(ll &a1, ll &b1)
{
	if(a1 == 0)
		return;
	ll t = gcd(a1, b1);
	a1 /= t;
	b1 /= t;
}	//分子分母约分

void standard_print(ll up, ll down)
{
    if(up * down < 0)      //保证负数的时候负数出现在分子
    {
        up = -abs(up);
        down = abs(down);
    }
	if(up == 0)
	{
		printf("0");
		return;
	}
	if(abs(up) >= abs(down))
	{
		ll k = up / down;
		up -= k * down;
		up = abs(up);
		if(k < 0)
			if(up == 0)
				printf("(-%lld)", abs(k));
			else printf("(-%lld %lld/%lld)", abs(k), up, down);
		else
			if(up == 0)
				printf("%lld", k);
			else printf("%lld %lld/%lld", k, up, down);
	}else
	{
		if(up < 0)
			printf("(%lld/%lld)", up, down);
		else
			printf("%lld/%lld", up, down);
	}
}	//控制标准输出形式，按照题目要求

void do_add(ll a1, ll b1, ll a2, ll b2)
{
	ll gcd_value = gcd(b1, b2);
	ll lcm_value = b1 / gcd_value * b2;
	ll up = a1 * (lcm_value / b1) + a2 * (lcm_value / b2);
	ll down = lcm_value;
	reduction(up, down);
	standard_print(a1, b1);
	printf(" + ");
	standard_print(a2, b2);
	printf(" = ");
	standard_print(up, down);
	printf("\n");
}

void do_sub(ll a1, ll b1, ll a2, ll b2)
{
	ll gcd_value = gcd(b1, b2);
	ll lcm_value = b1 / gcd_value * b2;
	ll up = a1 * (lcm_value / b1) - a2 * (lcm_value / b2);		//加法和减法唯一的区别就在这
	ll down = lcm_value;
	reduction(up, down);
	standard_print(a1, b1);
	printf(" - ");
	standard_print(a2, b2);
	printf(" = ");
	standard_print(up, down);
	printf("\n");
}	

void do_mult(ll a1, ll b1, ll a2, ll b2)
{
	ll up, down;
	if(a1 == 0 || a2 == 0)		//任意一乘数为0则整体为0，不用再计算了
	{
		up = 0;
	}else
	{
		up = a1 * a2;
		down = b1 * b2;
		reduction(up, down);
	}
	standard_print(a1, b1);
	printf(" * ");
	standard_print(a2, b2);
	printf(" = ");
	standard_print(up, down);
	printf("\n");
}

void do_ext(ll a1, ll b1, ll a2, ll b2)
{
	ll up, down;
	bool illegal = false;	//判断除法是否合法
	if(a2 == 0)
	{
		illegal = true;
	}else
	{
		up = a1 * b2;
		down = b1 * a2;
		reduction(up, down);
	}
	standard_print(a1, b1);
	printf(" / ");
	standard_print(a2, b2);
	printf(" = ");
	if(illegal)
		printf("Inf");
	else standard_print(up, down);
}

int main()
{
	ll a1,b1,a2,b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	reduction(a1, b1); reduction(a2, b2);
//	cin >> a1 >> b1;
//    standard_print(a1, b1);
	do_add(a1, b1, a2, b2);
	do_sub(a1, b1, a2, b2);
	do_mult(a1, b1, a2, b2);
	do_ext(a1, b1, a2, b2);
	return 0;
}
