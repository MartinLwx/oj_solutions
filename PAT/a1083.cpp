#include<bits/stdc++.h>
using namespace std;
struct student
{
	string name, id;
	int grade;
}a[10010];

bool cmp(student a, student b)
{
	return a.grade < b.grade;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i].name >> a[i].id >> a[i].grade;
	sort(a, a+n, cmp);
	int l, r;
	bool finded = false;     //表示是否至少有一个输出
	cin >> l >> r;
	if(l > r)   swap(l,r);
	for(int i=n-1;i>=0;i--)     //题目要求的是分数按高到低排，所以倒过来遍历
	{
		if(a[i].grade >= l && a[i].grade <= r)
		{
			finded = true;
			cout << a[i].name << " " << a[i].id << endl;
		}
	}
	if(!finded)
		cout << "NONE";
	return 0;
}

