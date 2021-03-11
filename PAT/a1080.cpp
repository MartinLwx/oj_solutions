#include<bits/stdc++.h>
using namespace std;
struct student
{
	int id;
	int ge, gi;
	int final_score;
	int choice[6];
	int rank;
}a[40010];
struct school
{
	int quota;       //配额
	int lastadmit;   //最后接受的学生编号
	int id[40010];   //存储录取的学生的编号
	int count;       //已录取人数
}sch[110];

bool cmp(student a, student b)
{
	if(a.final_score != b.final_score)
		return a.final_score > b.final_score;
	else return a.ge > b.ge;

}

bool cmpid(int x, int y)
{
    return a[x].id < a[y].id;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<m;i++)
    {
        scanf("%d", &sch[i].quota);
        sch[i].count = 0;
        sch[i].lastadmit = -1;   //-1表示还没招到人
    }

	for(int i=0;i<n;i++)
	{
		scanf("%d%d", &a[i].ge, &a[i].gi);
		a[i].final_score = (a[i].ge + a[i].gi) / 2;
		a[i].id = i;
		for(int j=0;j<k;j++)	scanf("%d", &a[i].choice[j]);
	}

	sort(a, a+n, cmp);
	for(int i=0;i<n;i++)
	{
		if(i >= 1 && a[i].final_score == a[i-1].final_score &&
			        a[i].ge == a[i-1].ge)
			a[i].rank = a[i-1].rank;
        else a[i].rank = i+1;
	}   //按照题目要求总分和GE分一样的时候为相同排名

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			int choice = a[i].choice[j];    //志愿学校
			int num = sch[choice].count;
			int last = sch[choice].lastadmit;
			//小于配额或最后一个录取的学生和当前的学生排名一样
			if(num < sch[choice].quota ||
            (last != -1 && a[i].rank == a[last].rank))
			{
				sch[choice].id[num] = i;
				sch[choice].lastadmit = i;    
				sch[choice].count++;
				break;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(sch[i].count > 0)
		{
			sort(sch[i].id, sch[i].id + sch[i].count, cmpid);
			for(int j=0;j<sch[i].count;j++)
			{
				printf("%d", a[sch[i].id[j]].id);  //根据数组的索引找到学生对应的id
				if(j != sch[i].count - 1 )
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
