#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n;
	cin >> n;
	LL up = (LL)sqrt(n * 1.0);
	LL ans = 0, length = 0;
	for(LL i=2;i<=up;i++)
	{
		LL tmp = 1;
		LL step = i;
		while(true)
		{
			tmp *= step;
			if(n % tmp != 0)	break;	//不是因子
			if(step - i + 1 > length)
			{
				ans = i;
				length = step - i + 1;
			}
			step++;
		}
	}
	if(length == 0)		//也就是这个是质数，因子只有1和自己
	{
		cout << 1 << endl;
		cout << n;		//不能输出1这个因子
	}
	else
	{
		cout << length << endl;
		for(LL i=0;i<length;i++)
		{
			cout << ans + i;
			if(i != length - 1)
				cout << "*";
		}
	}
	return 0;
}
