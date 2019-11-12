#include<bits/stdc++.h>
using namespace std;
vector<string> v;
void Init()
{
	char s[5] = {'S', 'H', 'C', 'D', 'J'};
	string tmp = "";
	v.push_back(" ");
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			tmp = s[i] + to_string(j);
			v.push_back(tmp);
		}
	}
	v.push_back("J1");
	v.push_back("J2");
}
int main()
{
	int n;
	cin >> n;
	Init();

	vector<string> tmp(v);
	int t;
	int order[54];
	for(int i=0;i<54;i++)
    {
        cin >> order[i];
    }

	while(n--)
	{
		for(int i=0;i<54;i++)
        {
            tmp[order[i]] = v[i+1];
        }
		v.clear();
		v.assign(tmp.begin(), tmp.end());
	}
	for(int i=1;i<v.size()-1;i++)
		cout << v[i] << " ";
	cout << v[v.size()-1];
	return 0;
}
