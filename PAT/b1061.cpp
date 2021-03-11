#include<bits/stdc++.h>
using namespace std;
int n,m;
int weight[101];
int right_ans[101];
int a[101];

int main()
{
	cin >> n >> m;
	for(int i=0;i<m;i++)	cin >> weight[i];
	for(int i=0;i<m;i++)	cin >> right_ans[i];
	while(n--)
	{
		int score = 0;
		for(int i=0;i<m;i++)
		{
			cin >> a[i];
			if(a[i] == right_ans[i])
				score += weight[i];
		}
		cout << score << endl;
	}
    return 0;
}
