#include<bits/stdc++.h>
using namespace std;
struct node
{
	string str;
	int test;
	int quiz;
	node(){}
	node(string _str, int _test, int _quiz): str(_str), test(_test), quiz(_quiz) {}
}a[1010];
int len = 0;

int get_index(int x)
{
	for(int i=0;i<len;i++)
		if(a[i].test == x)
			return i;
}


int main()
{
	int n;
	cin >> n;
	string s;
	int x,y;
	while(n--)
	{
		cin >> s >> x >> y;
		a[len++] = node(s, x, y);
	}
	int m;
	cin >> m;
	while(m--)
	{
		cin >> x;
		int i = get_index(x);
		cout << a[i].str << " " << a[i].quiz << endl;
	}
    return 0;
}
