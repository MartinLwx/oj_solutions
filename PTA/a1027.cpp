#include<bits/stdc++.h>
using namespace std;
string radix = "0123456789ABC";
string change_radix(int n)
{
	string ans = "";
	int t;
	if(n == 0)
        return "00";
	while(n)
	{
		t = n % 13;
		ans = radix[t] + ans;
		n /= 13;
	}
	if(ans.size() == 1)
		ans = "0" + ans;
	 return ans;
}
int main()
{
	int r,g,b;
	cin >> r >> g >> b;
	string ans = "";
	ans = change_radix(r) + change_radix(g) + change_radix(b);
	cout << '#' << ans;
	return 0;
}

