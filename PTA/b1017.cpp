#include<bits/stdc++.h>
using namespace std;
struct bignumber
{
	int num[1010];
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
		a.num[i] = s[s.size() - i - 1] - '0';		//低位存储对应数字的低位
    a.len = s.size();
}
bignumber divide(bignumber a, int b, int &r)
{
	bignumber c;
	c.len = a.len;
	for(int i=a.len-1;i>=0;i--)		//从高位除起
	{
		r = r * 10 + a.num[i];		
		if(r < b)	c.num[i] = 0;	//不够除
		else
		{
			c.num[i] = r / b;	//够除
			r %= b;
		}
	}
	while(c.num[c.len - 1] == 0 && c.len > 1)	//这里＞1是因为可能a<b，那么就是0
		c.len--;
	return c;
}
int main()
{
	string s;
	int b;
	cin >> s >> b;

	assignment(s);

	int r = 0;
	bignumber q =  divide(a, b, r);
	for(int i=q.len-1;i>=0;i--)
		cout << q.num[i];
	cout << " " << r;

	return 0;
}
