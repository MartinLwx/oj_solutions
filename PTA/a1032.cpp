#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
struct node
{
	int address;
	char data;
	int next;
}LinkList[MAXN];

int main()
{
	int f1, f2, n;
	scanf("%d%d%d", &f1, &f2, &n);

	int address, next;
	char data;
	while(n--)
	{
		scanf("%d %c %d", &address, &data, &next);
		LinkList[address].address = address;
		LinkList[address].data = data;
		LinkList[address].next = next;
	}
	int cur1 = f1, cur2 = f2;
	int l1 = 0, l2 = 0;
	while(cur1 != -1)
	{
		l1++;
		cur1 = LinkList[cur1].next;
	}

	while(cur2 != -1)
	{
		l2++;
		cur2 = LinkList[cur2].next;
	}
	int dis;
	if(l1 < l2)		//始终让cur1指向更长的部分
	{
		cur1 = f2;
		cur2 = f1;
		dis = l2 - l1;
	}else{
		cur1 = f1;
		cur2 = f2;
		dis = l1 - l2;
	}
	while(dis--)    cur1 = LinkList[cur1].next;     //统一起始位置

	while(cur1 != -1 && cur2 != -1)
	{
	    if(cur1 == cur2)
		{
			printf("%05d", LinkList[cur1].address);
			return 0;
		}
		cur1 = LinkList[cur1].next;
		cur2 = LinkList[cur2].next;
	}
	cout << -1;
	return 0;
}
//下面是双指针法的另一个解法
/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
struct node
{
	int address;
	char data;
	int next;
}LinkList[MAXN];

int main()
{
	int f1, f2, n;
	scanf("%d%d%d", &f1, &f2, &n);

	int address, next;
	char data;
	while(n--)
	{
		scanf("%d %c %d", &address, &data, &next);
		LinkList[address].address = address;
		LinkList[address].data = data;
		LinkList[address].next = next;
	}
	int cur1 = f1, cur2 = f2;
	while(cur1 != cur2)
	{
	    //cout << cur1 << " " << cur2 << endl;
		cur1 = cur1 == -1 ? f2 : LinkList[cur1].next;
        cur2 = cur2 == -1 ? f1 : LinkList[cur2].next;
	}
	if(cur1 == -1)
        cout << -1;
    else
        printf("%05d", cur1);
	return 0;
}
*/