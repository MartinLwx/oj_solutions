#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int vertical, bottom;
	vertical = (n + 2) / 3;
	bottom = n - 2*vertical + 2;
	
	int l = 0, r = n - 1;
	for(int i=0;i<vertical-1;i++)
	{
		cout << s[l];
		for(int j=0;j<bottom-2;j++)	cout << " ";
		cout << s[r];
		cout << endl;
		l++; r--;
	}
	for(int i=l;i<=r;i++)
		cout << s[i];
	return 0;
}

