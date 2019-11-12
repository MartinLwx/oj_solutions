#include<bits/stdc++.h>
using namespace std;
char q[10][10] = {"zero", "one", "two", "three", "four", "five",
				 "six", "seven", "eight", "nine"};
int main()
{
	char ch;
	int ans = 0;
	while(cin>>ch)
	{
		ans += ch - '0';
	}
	string s = to_string(ans);
	//cout << ans << endl;
	for(int i=0;i<s.size();i++)
	{
		if(i != s.size() - 1)
			cout << q[s[i]-'0'] << " ";
		else cout << q[s[i]-'0'];
	}
	return 0;
}

