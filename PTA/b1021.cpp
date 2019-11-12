#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<char,int> dict;
	string s;
	cin >> s;

	map<char,int>::iterator it;
	for(int i=0;i<s.size();i++)
	{
		it = dict.find(s[i]);
		if(it == dict.end())  //没找到
		{
			dict[s[i]] = 1;
		}else	dict[s[i]] += 1;
	}
	for(it=dict.begin();it!=dict.end();it++)
		printf("%c:%d\n", (*it).first, (*it).second);
	return 0;
}
