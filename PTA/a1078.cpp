#include<bits/stdc++.h>
using namespace std;
bool used[10010] = {0};

bool is_prime(int x)
{
	if(x <= 1)	return false;
	int up = (int)sqrt(x * 1.0);
	for(int i=2;i<=up;i++)
		if(x % i == 0)
			return false;
	return true;
}	//判断素数的方法

int main()
{
	int table_size, n;
	cin >> table_size >> n;
	if(!is_prime(table_size))
	{
		table_size++;
		while(!is_prime(table_size))
			table_size++;
	}	//检查表长是否为素数

	int t;
	for(int i=0;i<n;i++)
	{
		cin >> t;
		int pos = t % table_size;
		if(used[pos])     //位置被占用就用二次探测法（正向)
		{
			int step = 1;
			int found = false;
			for(;step<table_size;step++)
			{
				pos  = (t + step * step) % table_size;
				if(!used[pos])
				{
					found = true;
					break;
				}
			}
			if(found)
			{
			    used[pos] = true;
				if(i == 0)
					cout << pos;
				else
					cout << " " << pos;
			}else
			{
				if(i == 0)
					cout << "-";
				else
					cout << " " << "-";
			}
		}else	//如果位置没有被占用
		{
			used[pos] = true;
			if(i == 0)
				cout << pos;
			else
				cout << " " << pos;
		}

	}
	return 0;
}
