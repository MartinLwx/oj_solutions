#include<bits/stdc++.h>
using namespace std;
struct node
{
	char id[15];
    int score;
	int loc;    //location
	int loc_rank;
	int all_rank;
}a[30010];
int a_num = 0;

bool cmp(node a, node b)
{
    if(a.score != b.score)
        return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}


int main()
{
	int cases;
	scanf("%d", &cases);
	int cnt = 0;
    int level = 1;
    int n;
	while(cases--)
	{
		scanf("%d", &n);
		for(int j=0;j<n;j++)
		{
			scanf("%s %d", a[a_num].id, &a[a_num].score);
            a[a_num].loc = level;
            a_num++;
		}
        sort(a + cnt, a + cnt + n, cmp);
        a[cnt].loc_rank = 1;

        for(int i=cnt+1;i<cnt+n;i++)
        {
            if(a[i].score == a[i-1].score)
	            a[i].loc_rank = a[i-1].loc_rank;
	        else
	            a[i].loc_rank = i - (cnt + 1) + 2;
        }//对每个loc进行单独的排序
        cnt += n;
        level++;
	}
    sort(a, a + a_num, cmp);
    a[0].all_rank = 1;
    for(int i=1;i<a_num;i++)
    {
        if(a[i].score == a[i-1].score)
            a[i].all_rank = a[i-1].all_rank;
        else
            a[i].all_rank = i + 1;
    }
    printf("%d\n", cnt);
	for(int i=0;i<a_num;i++)
    {
        printf("%s %d %d %d\n", a[i].id, a[i].all_rank, a[i].loc, a[i].loc_rank);
    }
	return 0;
}
