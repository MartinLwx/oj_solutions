#include<bits/stdc++.h>
using namespace std;
struct node
{
	double pi, di;   //价格和到起点的距离
}a[510];
bool cmp(node a, node b)
{
	return a.di < b.di;
}

int main()
{
	double capacity, distance, run_per_gas;
	int stations;
	cin >> capacity >> distance >> run_per_gas >> stations;
	for(int i=0;i<stations;i++)
		cin >> a[i].pi >> a[i].di;
	a[stations].pi = 0;
	a[stations].di = distance;   //将重点堪称油价为0，距离起点为D的加油站
	sort(a, a+stations, cmp);

	if(a[0].di != 0)    //一开始的油量为0，如果最近的加油站距离不是0那么肯定不行
	{
		cout << "The maximum travel distance = 0.00\n";
		return 0;
	}
	int pos = 0;    //当前所在的加油站
	double best_len = capacity * run_per_gas;    //满油状态下能走得最远的距离
	double gas_owned = 0.0;    //当前状态之下有的油量
	double cheapest = 0.0;     //最后要花费的油钱
	while(pos < stations)
	{
		int next = -1;
		double min_price = 2100000000;
		for(int i=pos+1;i<=stations && a[i].di - a[pos].di <= best_len;i++)    //当前油量能走的最远距离
		{
			if(a[i].pi < min_price)
			{
				min_price = a[i].pi;
				next = i;
				if(min_price < a[pos].pi)
					break;
			}
		}
		if(next == -1)		break;

		double need = (a[next].di - a[pos].di) / run_per_gas;   //所需油量
		if(min_price < a[pos].pi)   //加油站k的油价小于当前油价
		{
			if(gas_owned < need)    //油量不足
			{
				cheapest += (need - gas_owned) * a[pos].pi;  //补足然后去下个更便宜的加油站
				gas_owned = 0;
			}else	gas_owned -= need;
		}else   //不然就先凑合着加，接着开
		{
			cheapest += (capacity - gas_owned) * a[pos].pi;
			gas_owned = capacity - need;
		}
		pos = next;
	}
	if(pos == stations)
		printf("%.2f\n", cheapest);
	else
		printf("The maximum travel distance = %.2f\n", a[pos].di + best_len);
	return 0;
}

