#include<bits/stdc++.h>
using namespace std;
int a[6] = {0};
int main()
{
	string s;
	getline(cin, s);

	for(int i=0;i<s.size();i++)
	{
		switch(s[i])
		{
			case 'P': a[0]++; break;
			case 'A': a[1]++; break;
			case 'T': a[2]++; break;
			case 'e': a[3]++; break;
			case 's': a[4]++; break;
			case 't': a[5]++; break;
			default: break;
		}
	}
	int len = 0;
	for(int i=0;i<6;i++)
        len += a[i];   //统计字母的个数用于控制输出
	int i = 0;
	string pat = "PATest";
	while(len != 0)
	{
		if(a[i] != 0)
        {
            cout << pat[i];
            a[i]--;
            len--;
        }
		i += 1;
		i %= 6;   //设置指针循环往复扫描数组，直到数组中的所有数字=0
	}
	return 0;
}

