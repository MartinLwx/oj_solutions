#include<bits/stdc++.h>
using namespace std;
int char2int(char x)
{
	if(x == 'B')	return 0;
	if(x == 'C')	return 1;
	if(x == 'J')	return 2;
}
int main()
{
	int n;
	cin >> n;
	int a1 = 0, a2 = 0,a3 = 0;
	int b1 = 0, b2 = 0,b3 = 0;
	char t1, t2;

	char mp[3] = {'B', 'C', 'J'};
	int cnt1[3] = {0};
	int cnt2[3] = {0};

	while(n--)
	{
	    cin >> t1 >> t2;
		int n1 = char2int(t1);
		int n2 = char2int(t2);
		if(n1 == n2)
		{
			a2++;
			b2++;
		}else if((n1+1) % 3 == n2)
		{
			a1++;
			b3++;
			cnt1[n1]++;
		}else
		{
			a3++;
			b1++;
			cnt2[n2]++;
		}
	}
	cout << a1 << " " << a2 << " " << a3 << endl;
	cout << b1 << " " << b2 << " " << b3 << endl;
	int index1 = 0, index2 = 0;
	for(int i=0;i<3;i++)
	{
		if(cnt1[i] > cnt1[index1])	index1 = i;
		if(cnt2[i] > cnt2[index2])	index2 = i;
	}
	cout << mp[index1] << " " << mp[index2];
	return 0;
}
