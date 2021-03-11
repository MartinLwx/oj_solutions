#include<bits/stdc++.h>
using namespace std;
struct record
{
	char id[8];
	int seconds;    //统一将时间转换为秒
	int status;
}a[10010], b[10010];  //分别是所有记录和有效记录
int b_num = 0;
bool cmp(record a, record b)
{
	if(strcmp(a.id, b.id) != 0)
		return strcmp(a.id, b.id) < 0;
	else return a.seconds < b.seconds;
}//先按车牌排序再按照时间来排序

bool cmp2(record a, record b)
{
	return a.seconds < b.seconds;
}




int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	char status[5];
	int hh, mm, ss;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d %s", &a[i].id, &hh, &mm, &ss, &status);
		a[i].seconds = hh * 3600 + mm * 60 + ss;
		if(strcmp(status, "in") == 0)	a[i].status = 0;   //表示in
		else a[i].status = 1; //表示out
	}
	sort(a, a+n, cmp);
	int longest = -1;

	map<string, int> t; //车牌->停留时间
	for(int i=0;i<n-1;i++)
	{
		if(!strcmp(a[i].id, a[i+1].id) &&
			a[i].status == 0 && a[i+1].status == 1)
		{
			b[b_num++] = a[i];
			b[b_num++] = a[i+1];
			int tmp = a[i+1].seconds - a[i].seconds;
			if(t.count(a[i].id) == 0)
				t[a[i].id] = 0;
			t[a[i].id] += tmp;
			longest = max(longest, t[a[i].id]);
		}
	}
	sort(b, b+b_num, cmp2);   //按时间排序

	int recode_pos = 0, ans = 0;
	for(int i=0;i<k;i++)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int tmp = hh * 3600+ mm * 60 + ss;
		while( recode_pos < b_num && b[recode_pos].seconds <= tmp)
		{
			if(b[recode_pos].status == 0)	ans++;
			else ans--;
			recode_pos++;
		}
		printf("%d\n", ans);
	}
	map<string, int>::iterator it;
	for(it=t.begin();it!=t.end();it++)
	{
		if(it->second == longest)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d\n", longest/3600, longest%3600/60, longest%60);
	return 0;
}

