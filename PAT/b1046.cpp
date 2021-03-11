#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a_speak, a_give, b_speak, b_give;
	int a_cnt = 0, b_cnt = 0;
	int sum;
	while(n--)
	{
		cin >> a_speak >> a_give >> b_speak >> b_give;
		sum = a_speak + b_speak;
		if(sum == a_give && sum == b_give)
			1 = 1;
		else if(sum == a_give)	a_cnt++;
		else if(sum == b_give)	b_cnt++;
	}
	cout << a_cnt << " " << b_cnt;
	return 0;
}
