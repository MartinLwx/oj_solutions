#include<bits/stdc++.h>
using namespace std;
struct bignumber
{
	int num[30];
	int len;
	bignumber()
	{
		memset(num, 0, sizeof(num));
		len = 0;
	}
}a;
void assignment(string s)
{
	for(int i=0;i<s.size();i++)
		a.num[i] = s[s.size() - i - 1] - '0';
	a.len = s.size();
}	//字符串->数组

bignumber multiply(bignumber a, int b)
{
	bignumber c;
	int carry = 0;
	for(int i=0;i<a.len;i++)
	{
		int t = a.num[i] * b + carry;
		c.num[c.len++] = t % 10;
		carry = t / 10;
	}
	while(carry != 0)	//到最高位的时候仍有可能进位
	{
		c.num[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
};
int main()
{
	string s;
	cin >> s;

	assignment(s);
	bignumber b = multiply(a, 2);


	int origin[10], double_origin[10];
	memset(origin, 0, sizeof(origin));
	memset(double_origin, 0, sizeof(double_origin));
    for(int i=0;i<a.len;i++)
		origin[a.num[i]]++;		//统计a用的数字的次数
	for(int i=0;i<b.len;i++)
		double_origin[b.num[i]]++;	//统计b用的数字的次数
	if(a.len != b.len)		//最基本要达到的是长度相等
	{
			cout << "No" << endl;
			for(int j=b.len-1;j>=0;j--)    cout << b.num[j];
			return 0;
	}


	for(int i=0;i<10;i++)
    {
		if(origin[i] != double_origin[i])
		{
			cout << "No" << endl;
			for(int j=b.len-1;j>=0;j--)    cout << b.num[j];
			return 0;
		}
    }
	cout << "Yes" << endl;
	for(int j=b.len-1;j>=0;j--)    cout << b.num[j];
	return 0;
}
