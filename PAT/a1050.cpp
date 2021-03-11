#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	map<char,int> mp;
	for(int i=0;i<s1.size();i++)
		if(mp.count(s1[i]) == 0)
			mp[s1[i]] = 1;
	for(int i=0;i<s2.size();i++)
		if(mp.count(s2[i]) == 0)  //该字符根本没有在s1中出现过
			continue;
		else
			mp[s2[i]] = 0;   //标记为0表示不可用
	for(int i=0;i<s1.size();i++)
		if(mp[s1[i]] != 0)
			cout << s1[i];
	return 0;
}

