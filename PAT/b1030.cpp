#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
	int N;
	long long p;
	scanf("%d%ld", &N, &p);
	for(int i=0;i<N;i++)
		scanf("%d", &a[i]);
	sort(a, a+N);

	int ans = 0;
	for(int i=0;i<N;i++)
    {
        for(int j=i+ans;j<N;j++)
        {
            if(a[j] <= a[i] * p)
                ans = max(ans, j-i+1);
            else break;
        }
    }
    printf("%d\n", ans);
	return 0;
}
