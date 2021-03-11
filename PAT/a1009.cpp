#include<bits/stdc++.h>
using namespace std;
struct node
{
	double a;
	int n;
	node(){}
	node(double _a, int _n): a(_a), n(_n){}
};//a*x^n
vector<node> v1;
vector<node> v2;
double a[2010] = {0};

int main()
{
	int k;

	cin >> k;
	int id;
	double tmp;
	while(k--)
	{
		cin >> id >> tmp;
		v1.push_back(node(tmp, id));
	}
	cin >> k;
	while(k--)
	{
		cin >> id >> tmp;
		v2.push_back(node(tmp, id));
	}
	double ans = 0.0;
	int index = 0;
	int base = 0;
	for(int i=0;i<v1.size();i++)
	{
		for(int j=0;j<v2.size();j++)
		{
			ans = v1[i].a * v2[j].a;
			index = v1[i].n + v2[j].n;
			//printf("ans:%d index:%d\n", ans, index);
			a[index] += ans;
		}
	}
	int cnt = 0;
	for(int i=0;i<2010;i++)
	{
		if(a[i] != 0)
			cnt++;
	}
	cout << cnt;
	for(int i=2009;i>=0;i--)
	{
		if(a[i] != 0)
            printf(" %d %.1f", i, a[i]);
	}
	return 0;
}
