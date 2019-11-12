#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n;
	scanf("%d", &n);

	int tmp;
	while(n--)
	{
		scanf("%d", &tmp);
		a[tmp]++;
	}
	int k;
	scanf("%d", &k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d", &tmp);
		cout << a[tmp];
		if (i != k)
			cout << " ";
	}
    return 0;
}
