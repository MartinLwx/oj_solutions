#include<bits/stdc++.h>
using namespace std;
vector<int> select_course[26*26*26*10 + 10];
int hashlize(char name[])
{
	int t = 0;
	for(int i=0;i<3;i++)
		t = t * 26 + (name[i] - 'A');
	t = t * 10 + (name[3] - '0');
	return t;
}	//字符串->哈希值
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);


	int course_id, cnt;
	char name[6];
	int hash_id;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d", &course_id, &cnt);
		for(int j=0;j<cnt;j++)
		{
			scanf("%s", name);
			hash_id = hashlize(name);	//根据字符串得到对应数字id
			select_course[hash_id].push_back(course_id);
		}
	}

	for(int i=0;i<n;i++)
	{
		scanf("%s", name);
		int id = hashlize(name);
		sort(select_course[id].begin(), select_course[id].end());	//题目的课程并不是按照课程号从小到大给出的
		printf("%s %d", name, select_course[id].size());
		for(int j=0;j<select_course[id].size();j++)
			printf(" %d", select_course[id][j]);
		printf("\n");
	}
	return 0;
}
