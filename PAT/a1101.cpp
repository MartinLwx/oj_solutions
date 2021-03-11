#include<bits/stdc++.h>
using namespace std;
int a[100010];
int left_max[100010];   //left_max[i]表示区间[1,i-1]最大的值	
int right_min[100010];	//right_min[i]表示区间[i,n]最小的值
const int INF = 1000000001;
int main()
{
	int n;
	cin >> n;

	for(int i=1;i<=n+1;i++)
        right_min[i] = INF;   //写完后面的发现这里的赋值好像有点多余

    left_max[0] = -1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		left_max[i] = max(a[i-1], left_max[i-1]);
	}
	right_min[n] = INF; //赋值为10^9+1最大值方便后面比较
	for(int i=n-1;i>=1;i--)
		right_min[i] = min(a[i+1], right_min[i+1]);

	vector<int> v;
	for(int i=1;i<=n;i++)
        if(a[i] > left_max[i] && a[i] < right_min[i])
			v.push_back(a[i]);

	//输出部分，先输出个数再输出具体数字
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++)
    {
        if(i != v.size()-1)
            cout << v[i] << " ";
        else
            cout << v[i];
    }
    cout << endl;	//比较坑的一点是如果一个也没有，这里也要换行，否则就会PE
	return 0;
}
