#include<bits/stdc++.h>
using namespace std;
struct mouse {
	int weight;
	int rank;
}mouse[1010];
int main()
{
	int np, ng;
	cin >> np >> ng;
	for (int i = 0; i < np; i++)	cin >> mouse[i].weight;

	queue<int> q;
	int t;
	for (int i = 0; i < np; i++)
	{
		cin >> t;
		q.push(t);
	}
	int tmp = np, group;
	while (q.size() != 1)
	{
		if (tmp % ng == 0)	group = tmp / ng;
		else	group = tmp / ng + 1;	//最后几个不够ng要多开一组
		for (int i = 0; i < group; i++)	//有几组处理几次
		{
			int max_one = q.front();
			for (int j = 0; j < ng; j++)
			{
				if (i * ng + j >= tmp)	break;	//不足ng就退出
				int front = q.front();
				if (mouse[front].weight > mouse[max_one].weight)
					max_one = front;
				mouse[front].rank = group + 1;
				q.pop();
			}
			q.push(max_one);	//当前老鼠检查完毕，检查下一只
		}
		tmp = group;	//一共group只老鼠晋级
	}
	mouse[q.front()].rank = 1;
	for (int i = 0; i < np; i++)
	{
		cout << mouse[i].rank;
		if (i < np - 1)	cout << " ";
	}
	return 0;
}