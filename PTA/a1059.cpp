#include<bits/stdc++.h>
using namespace std;
struct factor
{
	int x;	//质数
	int n;	//阶数
}fac[50];   
int primes[100100];
int prime_length = 0;
void gen_prime()
{
	int MAXN = 100100;
	bool flag[MAXN] = {0};
	for(int i=2;i<MAXN;i++)
	{
		if(!flag[i])
		{
			primes[prime_length++] = i;
			for(int j=i+i;j<MAXN;j+=i)	flag[j] = true;
		}
	}
}//质数筛法

int main()
{
	int n, n_copy;
	cin >> n;
	n_copy = n;
    gen_prime();

	int last_pos = 0;
	if(n == 1)	cout << "1=1";		//1是特殊情况
	else
	{
		int sqrt_value = (int)sqrt(n * 1.0);	//一个数的因子除了自身不会超过自身的根号n
		for(int i=0;primes[i]<sqrt_value && i<prime_length;i++)		//不超过根号n，以及不超过质数表的长度
		{
			while(n % primes[i] == 0)
			{
				fac[last_pos].x = primes[i];
				fac[last_pos].n == 0;
				while(n % primes[i] == 0)
				{
					fac[last_pos].n++;
					n /= primes[i];
				}
				last_pos++;
			}
			if(n == 1)  break;
		}

		if(n != 1)	//说明自己本身就是质数了
		{
			fac[last_pos].x = n;
			fac[last_pos].n = 1;
			last_pos++;
		}


		cout << n_copy << "=";
		for(int i=0;i<last_pos;i++)
		{
			if(fac[i].n != 1)
				printf("%d^%d", fac[i].x, fac[i].n);
			else
				printf("%d", fac[i].x);
			if(i != last_pos - 1)
				printf("*");
		}
	}
	return 0;
}
