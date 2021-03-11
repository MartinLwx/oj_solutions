#include<bits/stdc++.h>
using namespace std;
int a[100010] = {0};
int main()
{
	int n;
	scanf("%d", &n);

	int id, score;
	int max_id = -1;
	while(n--)
	{
		scanf("%d%d", &id, &score);
		max_id = max(id, max_id);
		a[id] += score;
	}
	int ans_id;
	int ans_score = -1;
	for(int i=0;i<=max_id;i++)
	{
		if(a[i] > ans_score)
		{
			ans_score = a[i];
			ans_id = i;
		}
	}
	cout << ans_id << " " << ans_score;
    return 0;
}
