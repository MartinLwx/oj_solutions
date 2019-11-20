#include<bits/stdc++.h>
using namespace std;
struct record
{
	int id;
	int score[5];
	bool flag; // 判断有没有通过编译的提交
	int total_score;
	int perfect;
}a[10010];

int p[6];
int n, k, m;
bool cmp(record a, record b)
{
	if(a.total_score != b.total_score)
		return a.total_score > b.total_score;
	else if(a.perfect != b.perfect)
		return a.perfect > b.perfect;
	else
		return a.id < b.id;
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		a[i].id = i;
		memset(a[i].score, -1, sizeof(a[i].score));	//默认设置为没有通过编译
		a[i].total_score = 0;
		a[i].flag = false;
		a[i].perfect = 0;
	}
} //初始化

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	init();

	for(int i=0;i<k;i++)	scanf("%d", &p[i]);

	int id, pos, mark;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d", &id, &pos, &mark);
		pos -= 1; //p[]数组是从0开始的，对齐索引
		if(mark != -1)	a[id].flag = true; //只要不是编译错误，那么起码有一次有效提交
		if(mark == p[pos] && a[id].score[pos] < p[pos])		a[id].perfect++; //第一次通过满分提交就 完美解决+1  避免多次统计
		if(mark == -1 && a[id].score[pos] == -1)	a[id].score[pos] = 0;	//第一次编译错误，分值记为0分，例子：00005 2 -1 对应分数为0
		if(mark > a[id].score[pos])	a[id].score[pos] = mark;   //超过之前的得分就覆盖
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(a[i].score[j] != -1)
				a[i].total_score += a[i].score[j];
		}
	}

	sort(a + 1, a + n + 1, cmp);
	int rank = 1;
	for(int i=1;i<=n;i++)
	{
		if(!a[i].flag)
			continue; //一题都没对的不用考虑
		else
		{
			if(i > 1 && a[i].total_score != a[i-1].total_score)	rank = i;
			printf("%d %05d %d", rank, a[i].id, a[i].total_score);
			for(int j=0;j<k;j++)
				if(a[i].score[j] == -1)
					printf(" -");
				else
					printf(" %d", a[i].score[j]);
			printf("\n");
		}
	}
	return 0;
}

