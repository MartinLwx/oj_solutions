#include<bits/stdc++.h>
using namespace std;
int a[110];
int a_copy[110];
int b[110];
int n;
bool judge(int a[], int b[])
{
	for(int i=0;i<n;i++)
		if(a[i] != b[i])
			return false;
	return true;
} //判断两个数组是否相等
bool insert_sort()
{
	bool equal_exist = false;
	for(int i=1;i<n;i++)    //共进行n-1趟排序
	{
		if(i != 1 && judge(a_copy, b))  //如果此时已经相等了，那么下面多执行的一轮相当于我们要的输出
			equal_exist = true;
		int pos = i;
		int t = a_copy[i];
		while(pos > 0 && a_copy[pos - 1] > t)
		{
			a_copy[pos] = a_copy[pos-1];
			pos--;
		}
		a_copy[pos] = t;
		if(equal_exist)
			return true;
	}
	return false;
}
bool merge_sort()
{
	bool equal_exist = false;
	//先是两两分组排序(i=2)，再是四四分组排序(i=4)
	for(int i=2;i<=2*n;i*=2)
	{
		if(i != 2 &&  judge(a_copy, b))
			equal_exist = true;
		for(int j=0;j<n;j+=i)
			sort(a_copy + j, a_copy + min(i + j, n));
		if(equal_exist)
			return true;
	}
}
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)	cin >> a[i];
	for(int i=0;i<n;i++)	cin >> b[i];
	for(int i=0;i<n;i++)	a_copy[i] = a[i];

    bool flag = insert_sort();
	if(flag)
	{
		cout << "Insertion Sort\n";
		cout << a_copy[0];
		for(int i=1;i<n;i++)
			cout << " " << a_copy[i];
	}else   //题目只有两种情况，不是插入排序就肯定是归并排序了
	{
		cout << "Merge Sort\n";
		for(int i=0;i<n;i++)	a_copy[i] = a[i];  //还原数组
		merge_sort();
		cout << a_copy[0];
		for(int i=1;i<n;i++)
			cout << " " << a_copy[i];
	}
	return 0;
}
