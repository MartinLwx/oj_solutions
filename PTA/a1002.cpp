#include<bits/stdc++.h>
using namespace std;
double coefficient[1010] = {0};
bool vis[1010] = {0};
int main()
{
	int k;
	int max_coe = -1;
	int id;
	double tmp;
	int cnt = 0; //统计不同系数的个数

	cin >> k;
	while(k--)
	{
		cin >> id >> tmp;
		coefficient[id] += tmp;
		if(!vis[id])
		{
			vis[id] = true;
			cnt++;
		}
		max_coe = max(max_coe, id);
	}
	cin >> k;
	while(k--)
	{
		cin >> id >> tmp;
		coefficient[id] += tmp;
		if(!vis[id])
		{
			vis[id] = true;
			cnt++;
		}
		max_coe = max(max_coe, id);
	}

	cout << cnt << " ";
	for(int i=max_coe;i>=0;i--)
	{
		if(vis[i] && cnt != 1)
		{
			cout << i << " " << coefficient[i] << " ";
		}
		if(vis[i] && cnt == 1)
		{
			cout << i << " " << coefficient[i];
		}
		cnt--;
		if(cnt == 0)
			break;
	}

	return 0;
}
