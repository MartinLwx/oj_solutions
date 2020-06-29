#include<bits/stdc++.h>
using namespace std;
struct node
{
	int address;
	int data;
	int next;
	int id;		//表示结点序号
}a[100010];
bool cmp(node a, node b)
{
	return a.id < b.id;
}
int main()
{
	for(int i=0;i<100010;i++)	a[i].id = 100010;	//表示当前是无效结点
	int init, n, k;
	cin >> init >> n >> k;
	int address, data, next;
	while(n--)
	{
		cin >> address >> data >> next;
		a[address].address = address;
		a[address].data = data;
		a[address].next = next;
	}
	int cur = init, length = 0;
	while(cur != -1)
	{
		a[cur].id = length++;	//表示在链表中的位置
		cur = a[cur].next;
	}	//遍历一次链表，并且给有效的结点以编号
	sort(a, a+100010, cmp);		//排序，此时前length个就是我们要的单链表了
	n = length;
    for(int i=0;i<n/k;i++)		//每隔k个进行分块
    {
    	for(int j=(i+1)*k-1;j>i*k;j--)		//输出每个块的除了最后一个的结点的信息
    		printf("%05d %d %05d\n", a[j].address, a[j].data, a[j-1].address);

    	printf("%05d %d ", a[i*k].address, a[i*k].data);
    	if(i < n/k - 1)		//不是最后一个块
    		printf("%05d\n", a[(i+2)*k - 1].address);
    	else
    	{
    		if(n%k == 0)	//已经到了链表的最后一个结点
    			printf("-1\n");
    		else
    		{
    			printf("%05d\n", a[(i+1)*k].address);
    			for(int t = n/k*k;t<n;t++)	//若还剩下<k个结点，直接按照原顺序输出
    			{
    				printf("%05d %d ", a[t].address, a[t].data);
    				if(t < n-1)
    					printf("%05d\n", a[t+1].address);
    				else
    					printf("-1\n");
    			}
    		}
    	}
	}

	return 0;
}
