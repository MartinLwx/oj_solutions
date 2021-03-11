#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<char,int> mp;
	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	for(int i=0;i<a.size();i++)
	{
		if(mp.count(a[i]) == 0)
		{
			mp[a[i]] = 1;
		}else mp[a[i]] += 1;
	}
	bool can_make = true;
	int need = 0;
	for(int i=0;i<b.size();i++)
	{
		if(mp.count(b[i]) == 0 || mp[b[i]] == 0)  //找不到指定颜色的珠子或者该珠子用完
		{
			can_make = false;
			need++;
		}else
		{
			mp[b[i]] -= 1;
		}
	}
	if(can_make)
	{
		map<char,int>::iterator it;
		int extra = 0;
		for(it=mp.begin();it!=mp.end();it++)
			extra += it->second;
		cout << "Yes " << extra;
	}else cout << "No " << need;
	return 0;
}