#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void get_num(int n, int b)
{
	int t;
	while(n)
	{
		t = n % b;
		v.push_back(t);
		n /= b;
	}
}
int main()
{
	int n,b;
	cin >> n >> b;

	get_num(n,b);
	reverse(v.begin(), v.end());
	bool same = true;
	for(int i=0;i<v.size()/2;i++)
		if(v[i] != v[v.size() - 1 - i])
			same = false;
	if(same)
		cout << "Yes\n";
	else cout << "No\n";
	cout << v[0];
	for(int i=1;i<v.size();i++)
		 cout << " " << v[i];
	return 0;
}

