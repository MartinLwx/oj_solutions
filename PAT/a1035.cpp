#include<bits/stdc++.h>
using namespace std;
struct user
{
	string id;
	string password;
}a[1010];
int a_num = 0;
int main()
{
	int n;
	cin >> n;
	string id, ps;
	bool modify = false;
	for(int j=0;j<n;j++)
	{
		cin >> id >> ps;
		modify = false;	//表示有无修改过
		for(int i=0;i<ps.size();i++)
		{
			if(ps[i] == '1')
			{
				modify = true;
				ps[i] = '@';
			}else
			if(ps[i] == '0')
			{
				modify = true;
				ps[i] = '%';
			}else
			if(ps[i] == 'l')
			{
				modify = true;
				ps[i] = 'L';
			}else
			if(ps[i] == 'O')
			{
				modify = true;
				ps[i] = 'o';
			}
		}
		if(modify)
		{
			a[a_num].id = id;
			a[a_num++].password = ps;
		}
	}
	if(a_num == 0)
        if(n != 1)
            printf("There are %d accounts and no account is modified", n);
        else
            printf("There is 1 account and no account is modified");
	else
	{
		cout << a_num<< endl;
		for(int i=0;i<a_num;i++)
		{
			cout << a[i].id << " " << a[i].password;
			cout << endl;
		}
	}
	return 0;
}

