#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;

	int a = 1;
	int ans =0;
	int left, now, right;
	while(!n/a)
	{
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if(now == 0)
			ans += left * a;
		else if(now == 1)
			ans += left * a + 1 + right;
		else if(now >= 2)
			ans += (left + 1) * a
		a *= 10;
	}

	cout << ans;
	return 0;
}

245 = 
