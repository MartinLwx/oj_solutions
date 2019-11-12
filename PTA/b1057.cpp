#include<bits/stdc++.h>
using namespace std;
string s;
int count_0 = 0;
int count_1 = 0;

void get_01(int x)
{
	while(x)
	{
		if(x%2==0)
			count_0++;
		else
			count_1++;
		x /= 2;
	}
}

int main()
{
	getline(cin, s);
	int value = 0;
	int tmp;
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
		{
			s[i] = tolower(s[i]);
			tmp = (s[i] - 'a') + 1;
			value += tmp;
		}
	}

	get_01(value);
	cout << count_0 << " " << count_1;
    return 0;
}
