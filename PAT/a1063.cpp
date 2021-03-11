#include<bits/stdc++.h>
using namespace std;
set<int> v[60];
int main()
{
	int n;
	scanf("%d", &n);

	int cnt = 0;
	int t;
	for(int j=1;j<=n;j++)		//注意集合的下标是从1开始的
	{
		scanf("%d", &cnt);
		for(int i=0;i<cnt;i++)
		{
			scanf("%d", &t);
			v[j].insert(t);
		}
	}

	int query;
	scanf("%d", &query);
	int a, b;
	for(int i=0;i<query;i++)
	{
		scanf("%d %d", &a, &b);
		int sum = v[b].size(), equals = 0;		//总数量初始化为b的大小
		set<int>::iterator it;
		for(it = v[a].begin(); it!=v[a].end();it++)
		{
			if(v[b].find(*it) != v[b].end())	//在b集合中找有无a的元素
				equals++;
			else	sum++;
		}
		printf("%.1f%%\n", equals * 100.0 / sum);
	}
	return 0;
}
