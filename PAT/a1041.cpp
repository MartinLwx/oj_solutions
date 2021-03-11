#include<bits/stdc++.h>
using namespace std;
int record[10010];
int len = 0;
int main()
{
	int n;
	scanf("%d", &n);

	int t;
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &t);
		if(mp.count(t) == 0)     //判断是否之前有出现过
		{
			record[len++] = t;  //记录读进来的顺序
			mp[t] = 1;
		}else mp[t]++;    //否则出现次数+1
	}
	for(int i=0;i<len;i++)
	{
		if(mp[record[i]] == 1)
		{
			printf("%d\n", record[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}

