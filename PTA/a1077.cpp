#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main()
{
	int n;
	scanf("%d\n", &n);
	int shortest = 500;
	string s;
	for(int i=0;i<n;i++)
	{
		getline(cin, s);
		if(s.size() < shortest) shortest = s.size();
		reverse(s.begin(), s.end());
		v.push_back(s);
	}

	bool right;
	int index = 0;
	for(int i=0;i<shortest;i++)
	{
		char ch = v[0][i];
		right = true;
		for(int j=1;j<n;j++)
		{
			if(v[j][i] != ch)
			{
				right = false;
				break;
			}
		}
		if(right)	index++;
		else	break;
	}

	if(index == 0)
		cout << "nai";
	else
		for(int i=index-1;i>=0;i--)
			cout << v[0][i];
	return 0;
}

