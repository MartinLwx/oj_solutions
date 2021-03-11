#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n, m;
	cin >> n >> m;

	map<int, int> mp;
	for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(mp.count(a[i]) != 0)   //存在相同的数字个数要对应相加
            mp[a[i]]++;
        else
            mp[a[i]] = 1;
    }
	sort(a, a+n);   //升序保证v1<=v2
	for(int i=0;i<n;i++)
	{
		int t = m - a[i];
		if( (t != a[i] && mp.count(t) != 0) ||
            (t == a[i] && mp[t] > 1) )  //两个数不相等的时候有就行了，否则该数要不止一个
		{
			cout << a[i] << " " << t;
			return 0;
		}
	}
	cout << "No Solution";
	return 0;
}