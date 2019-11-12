#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
int main()
{
	int n;
	double e;
	int D;
	cin >> n >> e >> D;

	int may_unused = 0;
	int abs_unused = 0;
	int days;
	double use;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &days);
		int lower_e = 0;
		int beyond_D = 0;
		bool condition1 = false;
		for(int j=0;j<days;j++)
		{
			scanf("%lf", &use);
			if(use < e - EPS)	lower_e++;
		}
		if(lower_e > days/2)
		{
			condition1 = true;
			may_unused++;
		}
		if(condition1 && days > D)
        {
            abs_unused++;
            may_unused--; //空置 就不是 可能空置了
        }
	}
	double ans1 = may_unused * 1.0 / n;
	double ans2 = abs_unused * 1.0 / n;
	printf("%.1f%% %.1f%%", ans1*100, ans2*100);
}
