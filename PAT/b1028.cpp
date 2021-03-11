#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
	string name;
	int year, month, day;
}oldest, youngest, l, r;

void Init()
{
	youngest.year = l.year = 1814;
	oldest.year = r.year = 2014;
	youngest.month = oldest.month = l.month = r.month = 9;
	youngest.day = oldest.day = l.day = r.day = 6;
}

bool less2(node a, node b)
{
	if(a.year != b.year)
		return a.year <= b.year;
	else if(a.month != b.month)	return a.month <= b.month;
	else return a.day <= b.day;
}

bool more2(node a, node b)
{
	if(a.year != b.year)
		return a.year >= b.year;
	else if(a.month != b.month)	return a.month >= b.month;
	else return a.day >= b.day;
}

int main()
{
	int n;
	cin >> n;
	Init();

	node tmp;
	int num = 0;
	while(n--)
	{
		cin >> tmp.name;
		scanf("%d/%d/%d", &tmp.year, &tmp.month, &tmp.day);
		if(less2(tmp, r) && more2(tmp , l))
		{
			num++;
			if(less2(tmp, oldest))	oldest = tmp;
			if(more2(tmp, youngest))	youngest = tmp;
		}
	}
	if(num == 0)
		cout << "0" << endl;
	else cout << num << " " << oldest.name << " " << youngest.name;
	return 0;
}

