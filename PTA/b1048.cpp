#include<bits/stdc++.h>
using namespace std;

char get_char(int x)
{
	if(x<=9 && x>=0)
		return to_string(x)[0];
	if(x == 10)	return 'J';
	if(x == 11)	return 'Q';
	if(x == 12)	return 'K';
}
int get_value(char c)
{
    if(c == 'J') return 10;
    if(c == 'Q') return 11;
    if(c == 'K') return 12;
    return c - '0';
}
int main()
{
	string a,b;
	cin >> a >> b;
	int odd = true;

	vector<char> ans;
	int i = a.size() - 1;
	int j = b.size() - 1;
    if(i<j)
        for(int k=0;k<j-i;k++)  a = '0' + a;
    else
        for(int k=0;k<i-j;k++)  b = '0' + b;



    int equal_length = max(i,j);
	while(equal_length >= 0)
	{
		int value_a = get_value(a[equal_length]);
		int value_b = get_value(b[equal_length]);
		if(odd)
		{
			int value_mod = (value_a + value_b) % 13;
			ans.push_back(get_char(value_mod));
		}else
		{
			int value_sub = value_b - value_a;
			if(value_sub < 0)	value_sub += 10;
			ans.push_back(get_char(value_sub));
		}
		equal_length--;
		odd = !odd;
	}
	reverse(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		cout << ans[i];
	return 0;
}
