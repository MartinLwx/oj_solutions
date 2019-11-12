#include<bits/stdc++.h>
using namespace std;
struct node
{
	char name[20];
	int hh,mm,ss;
}small, big;

void Init()
{
	big.hh = big.mm = big.ss = 0;
	small.hh = 24;
	small.mm = small.ss = 59;
}

bool early(node a, node b)
{ //true-a的时间早于b的时间
	if(a.hh != b.hh)	return a.hh <= b.hh;
	else if(a.mm != b.mm)	return a.mm <= b.mm;
	else return a.ss <= b.ss;
}
int main()
{
	int m;
	cin >> m;
	Init();

	node tmp;
	while(m--)
	{
		scanf("%s %d:%d:%d", &tmp.name, &tmp.hh, &tmp.mm, &tmp.ss);
		if(early(tmp, small))
			small = tmp; //更新最早
		scanf("%d:%d:%d", &tmp.hh, &tmp.mm, &tmp.ss);
		if(early(big, tmp))
			big = tmp;  //更新最晚
	}
	cout << small.name << " " << big.name;
	return 0;
}

