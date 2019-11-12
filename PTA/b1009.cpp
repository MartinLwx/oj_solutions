#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> a;
	string tmp;
	while(cin >> tmp)
	{
		a.push_back(tmp);
	}
	vector<string>::iterator it;
	for(int i = a.size()-1; i>=0;i--)
	{
		if(i != 0)
			cout << a[i] << " ";
		else
			cout << a[i];
	}
    return 0;
}
