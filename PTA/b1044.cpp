#include<bits/stdc++.h>
using namespace std;
map<string, int> m;		// 火星文->数字
string ans[200];	// 数字->火星文
string digits[13] = {"tret", "jan", "feb", "mar", "apr", "may",
					 "jun", "jly", "aug", "sep", "oct", "nov",
					 "dec"};
string times_digits[13] = {"tret", "tam", "hel", "maa", "huh", "tou",
						 "kes", "hei", "elo", "syy", "lok", "mer",
						 "jou"};
void Init()
{
	for(int i=0;i<13;i++)
	{
		ans[i] = digits[i];
		m[digits[i]] = i;
		ans[i * 13] = times_digits[i];
		m[times_digits[i]] = i * 13;
	}

	for(int i=1;i<13;i++)
		for(int j=1;j<13;j++)
		{
			string tmp = times_digits[i] + " " + digits[j];
			ans[i * 13 + j] = tmp;
			m[tmp] = i * 13 + j;
		}	//手动模拟打表

}
int string2int(string s)
{
	int value = 0;
	for(int i=0;i<s.size();i++)
		value = value * 10 + (s[i] - '0');
	return value;
}	//将字符串->数字
int main()
{
	int n;
	string s;
	cin >> n;
	getchar();		// 处理换行符
	Init();		// 初始化打表过程

	for(int i=0;i<n;i++)
	{
		getline(cin, s);
		if(isdigit(s[0]))	// 数字
		{
			int value = string2int(s);
			cout << ans[value] << endl;
		}else
		{
			cout << m[s] << endl;
		}
	}
	return 0;
}
