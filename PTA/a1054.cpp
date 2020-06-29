#include<bits/stdc++.h>
using namespace std;
map<int, int> image;
int main()
{
	int m, n;
    cin >> m >> n;
	int t;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d", &t);    // 这里使用cin会超时噢!
			if(image.count(t) == 0)		// 统计为0说明是第一次遇到这个数字
				image[t] = 1;
			else
				image[t]++;
		}
	int half = m * n / 2;
	map<int, int>::iterator it;
	for(it=image.begin();it!=image.end();it++)
		if(it->second > half)
		{
			cout << it->first;
			break;
		}
	return 0;
}
