#include<bits/stdc++.h>
using namespace std;
struct bignumber
{
	int num[1000];
	int len;
	bignumber()
	{
		memset(num, 0, sizeof(num));
		len = 0;
	}
};
bool is_palindromic(bignumber a)
{
	for(int i=0;i<=a.len/2;i++)
		if(a.num[i] != a.num[a.len - i - 1])
			return false;
	return true;
}	//判断是否为回文
bignumber assignment(string s)
{
	bignumber a;
	for(int i=0;i<s.size();i++)
		a.num[i] = s[s.size() - i - 1] - '0';
	a.len = s.size();
	return a;
}	//字符串->大数，数值低位对应数组低位
bignumber get_reverse(bignumber a)
{
	bignumber b;
	for(int i=0;i<a.len;i++)
		b.num[i] = a.num[a.len - i - 1];
	b.len = a.len;
	return b;
}	//返回a的reverse组成的数
bignumber big_add(bignumber a, bignumber b)
{
	bignumber c;
	int carry = 0;
	for(int i=0;i<a.len;i++)
	{
		c.num[c.len] = a.num[i] + b.num[i] + carry;
		carry = c.num[c.len] / 10;
		c.num[c.len++] %= 10;
	}
	while(carry!=0)
	{
		c.num[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}	//大数相加，此处a和b的长度一定是相等的
int main()
{
	bignumber a,b;
	string s;
	int k;
	cin >> s >> k;
	a = assignment(s);
	b = get_reverse(a);
	bignumber c;

    if(is_palindromic(a))
    {
        for(int i=a.len-1;i>=0;i--)	cout << a.num[i];
        cout << endl;
        cout << 0;
        return 0;
    }	//如果本身就是，就不用再做下面的运算了

	int step = 0;
	for(int i=1;i<=k;i++)
	{
		c = big_add(a,b);
		step++;
		if(is_palindromic(c))
			break;
        a = c;
        b = get_reverse(a);
	}
	for(int i=c.len-1;i>=0;i--)	cout << c.num[i];
	cout << endl;
	step <= k ? cout << step : cout << k;
	return 0;
}
