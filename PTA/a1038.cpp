#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
	return a+b < b+a;
}

int main()
{
	int n;
	cin >> n;
	std::vector<string> v;
	string s;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	string ans = "";
	for(int i=0;i<v.size();i++)
		ans += v[i];
	
	int pos = 0;
	while(ans[pos] == '0')	pos++;
	if(pos == ans.size())    //去除所有前导0之后，如果到了末端说明整个字符串都是0，此时输出0 
		cout << 0;
	else
		for(int i=pos;i<ans.size();i++)
			cout << ans[i];
	return 0;
}

