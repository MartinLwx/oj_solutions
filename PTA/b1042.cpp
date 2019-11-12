#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	map<char,int> dict;
	map<char,int>::iterator it;
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
		{
		    it = dict.find(s[i]);
			if(it != dict.end())
				it->second += 1;
			else
				dict[s[i]] = 1;
		}
	}
	char maxchar;
	int maxvalue = -1;
	for(it=dict.begin();it!=dict.end();it++)
	{
		if(it->second > maxvalue)
		{
			maxvalue = it->second;
			maxchar = it->first;
		}
	}
	cout << maxchar << " " << maxvalue;
    return 0;
}
