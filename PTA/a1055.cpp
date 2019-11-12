#include<bits/stdc++.h>
using namespace std;
struct billionaire
{
	string name;
	int age, worth;
}a[100010];

bool cmp(billionaire a, billionaire b)
{
	if(a.worth != b.worth)
		return a.worth > b.worth;
	else if(a.age != b.age)
		return a.age < b.age;
	else
		return a.name < b.name;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].name >> a[i].age >> a[i].worth;
	}
	sort(a, a+n, cmp);
	int m, l, r;
	for(int i=0;i<k;i++)
	{
		cin >> m >> l >> r;
		cout << "Case #" << i+1 << ":" << endl;
		int pos = 0;
		int tmp = m;    //暂时存储m的值
		while(pos != n)   //遍历一遍排序好的数据，逐个判断年龄是否满足条件
		{
			if(a[pos].age >= l && a[pos].age <= r)  //满足年龄条件
			{
				m--;
				cout << a[pos].name << " " << a[pos].age << " " << a[pos].worth << endl;
			}
			if(m == 0)  break;
			pos++;
		}
		if(m == tmp)   cout << "None" << endl; //这里不能用m!=0，不然会报错，猜测可能是有找到部分没完全找到的情况下多输出了None
	}
	return 0;
}

