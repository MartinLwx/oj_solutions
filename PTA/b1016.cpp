#include<bits/stdc++.h>
using namespace std;
int get_num(string s, int x)
{
	string ans = "";
	for(int i=0;i<s.size();i++)
	{
		int num = s[i] - '0';
		if(num == x)
			ans += (char)(x + '0');
	}
	stringstream ss;
	int value = 0;
	ss << ans;
	ss >> value;
	return value;
}
int main()
{
	string a, b;
	int da, db;
	cin >> a >> da >> b >> db;
	cout << get_num(a,da) + get_num(b,db);
    return 0;
}