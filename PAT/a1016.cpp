#include<bits/stdc++.h>
using namespace std;
struct record
{
	char name[25];
	int mm1, dd, hh, mm;
	bool is_complete;
}a[1010];

int charge[24] = {10, 10, 10, 10, 10, 
				  10, 20, 20, 20, 15,
				  15, 15, 15, 15, 15,
				  15, 20, 30, 20, 15,
				  15, 10, 10, 10};

bool cmp(record a, record b)
{
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	else if(a.mm1 != b.mm1)		return a.mm1 < b.mm1;
	else if(a.dd != b.dd)		return a.dd < b.dd;
	else if(a.hh != b.hh)		return a.hh < b.hh;
	else return a.mm < b.mm;
} //按照名字-月-日-时-分来排序

void cal(int start, int off, int& time, int& money)
{
	record tmp = a[start];
	while(tmp.dd < a[off].dd || tmp.hh < a[off].hh || tmp.mm < a[off].mm)
	{
		time++;
		money += charge[tmp.hh];
		tmp.mm++;
		if(tmp.mm >= 60)
		{
			tmp.mm = 0;
			tmp.hh++;
		}
		if(tmp.hh >=24)
		{
			tmp.hh = 0;
			tmp.dd++;
		}
	}
}

int main()
{
	for(int i=0;i<24;i++)
		scanf("%d", &charge[i]);
	int n;
	scanf("%d", &n);
	char state[10];
	
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d:%d %s", &a[i].name, &a[i].mm1, &a[i].dd, &a[i].hh, &a[i].mm, &state);
		if(strcmp(state,"on-line") == 0)
			a[i].is_complete = true;	
		else if(strcmp(state, "off-line") == 0)
			a[i].is_complete = false;
	}

	sort(a, a+n, cmp);  //按照发生时间进行排序
	int start = 0, end, next_pos;
	while(start < n)
	{
		int has_pair = 0;
		next_pos = start;
		while(next_pos < n && strcmp(a[next_pos].name, a[start].name) == 0)
		{
			if(has_pair == 0 && a[next_pos].is_complete == true)
				has_pair = 1;
			else if(has_pair == 0 && a[next_pos].is_complete == false)
				has_pair = 2;
			next_pos++;
		}

		if(has_pair < 2)
		{
			start = next_pos;
			continue;
		}
		int sum = 0;
		printf("%s %02d\n", a[start].name, a[start].mm1);
		while(start < next_pos)
		{
			whlie(start < next_pos - 1 
				&& !(a[start].is_complete == true && a[start+1].is_complete == false))
				start++;   //找第一个连续的on-line,以及随后的off-line
			if(start + 1 == next_pos)
			{
				start = next_pos;
				break;
			}
			printf("%02d:%02d:%02d ", a[start].dd, a[start].hh, a[start].mm);
			printf("%02d:%02d:%02d ", a[start+1].dd, a[start+1].hh, a[start+1].mm);
			int time = 0, money = 0;
			cal(start, start+1, time, money);
			sum += money;
			printf("%d $%.2f\n", time, money /100.0);
			start = start + 1;
		}
		printf("Total amount: $%.2f\n", sum / 100.0);
	}
	return 0;
}

