#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
	if(x <= 1)	return false;
	int up = (int)sqrt(x * 1.0);
	for(int i=2;i<=up;i++)
		if(x % i == 0)
			return false;
	return true;
}	//判断素数的方法

int getR(int n, int d)
{
	vector<int> v;
	int t = 0;
	while(n)
	{
		t = n % d;
		v.push_back(t);
		n /= d;
	}
	int r_value = 0;
	for(int i=0;i<v.size();i++)
	{
		r_value += v[i] * pow(d, v.size() - i - 1);
	}
	return r_value;
}   //根据进制得到反转之后的值

int main()
{
	int n, d;
	while(cin >> n)
	{
		if(n < 0)	break;
		else	cin >> d;
		if(!is_prime(n))	//如果本身不是素数，没有进一步检查的必要
		{
			cout << "No" << endl;
			continue;
		}
		else
		{
			int reverse_value = getR(n,d);
			if(is_prime(reverse_value))
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
