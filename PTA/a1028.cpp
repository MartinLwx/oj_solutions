#include<bits/stdc++.h>
using namespace std;
struct student
{
	char id[7];
	char name[9];
	int grade;
}a[100010];

bool cmp1(student a, student b)
{
	return strcmp(a.id, b.id) < 0;
}   //比较id

bool cmp2(student a, student b)
{
	if(strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	else
		return strcmp(a.id, b.id) < 0;
}//比较名字，相同就比较id

bool cmp3(student a, student b)
{
	if(a.grade != b.grade)
		return a.grade < b.grade;
	else
		return strcmp(a.id, b.id) < 0;
}//比较分数，相同就比较id

int main()
{
	int n, c;
	cin >> n >> c;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].id >> a[i].name >> a[i].grade;
	}
	switch(c)
	{
		case 1:
			sort(a, a+n, cmp1);
			break;  //执行完一个分支要break
		case 2:
			sort(a, a+n, cmp2);
			break;  //执行完一个分支要break
		case 3:
			sort(a, a+n, cmp3);
	}
	for(int i=0;i<n;i++)
	{
		cout << a[i].id << " " << a[i].name << " " <<a[i].grade;
		if(i != n-1)    cout << endl;   //避免输出额外空格
	}
	return 0;
}

