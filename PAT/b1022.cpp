#include<bits/stdc++.h>
using namespace std;
string transform(int x, int d)
{
	string tmp = "";
	if(x == 0)
        return "0";
	while(x)
	{
		tmp = tmp + (char)(x%d + '0');
		x /= d;
	}
	reverse(tmp.begin(),tmp.end());
	return tmp;
}
int main()
{
	int a,b;
	cin >> a >> b;
	int d;
	cin >> d;
	string ans = transform(a+b, d);
	cout << ans;
    return 0;
}
