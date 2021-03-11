#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n,m;
	int i = 0;
	while(cin>>n>>m)
	{
		if(m!=0){      //m=0就是常数项了，所以不用加进去
			v.push_back(n*m);
			v.push_back(m-1);
		}
	}
	if(v.size() == 0)   //递减的情况给出来，如果直接0 0，说明到底了
    {
        cout << "0 0";
        return 0;
    }
	for(int i=0;i<v.size();i++)
	{
		if(i == v.size()-1)
			cout << v[i];
		else
			cout << v[i] << " ";
	}
	return 0;
}
