#include<bits/stdc++.h>
using namespace std;
int score_sum[1010] = {0};


int main()
{
	int n;
	scanf("%d", &n);

	int team,id;
	int score;
	for(int i=0;i<n;i++)
	{
		scanf("%d-%d %d", &team, &id, &score);
		score_sum[team] += score;
	}

	int max_team = -1;
	int max_score = -1;
	for(int i=1;i<=1000;i++)
	{
		if(score_sum[i] > max_score)
		{
			max_score = score_sum[i];
			max_team = i;
		}
	}
	cout << max_team << " " << max_score;
    return 0;
}
