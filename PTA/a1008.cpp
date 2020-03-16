#include<bits/stdc++.h>
using namespace std;

int main()
{
	int time = 0;	//表示总耗时
	int floor = 0;	//表示当前位于哪一层
	int n, target;
	cin >> n;
	while(n--)
	{
		cin >> target;
		if(target > floor)
		{
			time += 6*(target - floor);		//每爬一层+6s
			time += 5;
			floor = target;
		}else
		{
			time += 4*(floor - target);		//每下一层+4s
			time += 5;
			floor = target;
		}
	}
	cout << time;
	return 0;
}
