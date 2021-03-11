#include<bits/stdc++.h>
using namespace std;
vector<int> courses[2510];
char names[40010][6];
bool cmp(int a, int b)
{
	return strcmp(names[a], names[b]) < 0;
}	//因为vector存储的是下标，所以是根据下标来对字符串进行排序
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	int cnt, tmp;
	for(int i=0;i<n;i++)
	{
		scanf("%s", &names[i]);
		scanf("%d", &cnt);
		for(int j=0;j<cnt;j++)
		{
			scanf("%d", &tmp);
			courses[tmp].push_back(i);	//在相应的课程里存储对应的学生的ID(根据ID去names里可以查询到名字)
		}
	}
	for(int i=1;i<=k;i++)
	{
		sort(courses[i].begin(), courses[i].end(), cmp);
		printf("%d %d\n", i, courses[i].size());
		for(int j=0;j<courses[i].size();j++)
            printf("%s\n", names[courses[i][j]]);
	}
	return 0;
}
