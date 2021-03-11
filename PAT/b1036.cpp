#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c;
	for(int i=0;i<n;i++)	cout << c;
	cout << endl;

	for(int i=0;i<round(0.5 * n) - 2;i++)
	{
		cout << c;
		for(int j=0;j<n-2;j++)	cout << " ";
		cout << c;
		cout << endl;
	}

	for(int i=0;i<n;i++)	cout << c;
	return 0;
}

