#include<bits/stdc++.h>
using namespace std;
int n;
string transfer(string s, int &x)
{
	while(s.size() > 0 && s[0] == '0')	s.erase(s.begin());		//为了应对形如000.0这样的数据，去掉小数点前面的0
	if(s[0] != '.')		// >1的数
	{
		std::size_t pos = s.find(".");	// 查看是否有小数点
		if(pos != s.npos)	// 如果找到了小数点
		{
			x = pos;
			s.erase(s.begin() + pos);	// 去除小数点
		}else	x = s.size();
	}else		// <1的数
	{
		s.erase(s.begin());
		while(s.size() > 0 && s[0] == '0')		// 处理形同0.000234这样的数据，
		{
			s.erase(s.begin());
			x--;
		}
	}

	if(s.size() == 0)	x = 0;

	string ans;
	if(s.size() > n)
		for(int i=0;i<n;i++)	ans += s[i];
	else
	{
		for(int i=0;i<s.size();i++)		ans += s[i];
		for(int i=0;i<n - s.size();i++)		ans += '0';		// 不足的添加0补足位数
	}
	return ans;
}	// 原始字符串->有效数字^指数
int main()
{
	string a, b, c, d;
	cin >> n >> a >> b;
	int x1 = 0, x2 = 0;
	c = transfer(a, x1);
	d = transfer(b, x2);
	if(c == d && x1 == x2)
		cout << "YES 0." << c << "*10^" << x1;
	else
		cout << "NO 0." << c << "*10^" << x1 << " 0." << d << "*10^" << x2;
	return 0;
}
