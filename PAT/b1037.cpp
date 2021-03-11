#include<bits/stdc++.h>
using namespace std;

int main()
{
	int g1,s1,k1;
	int g2,s2,k2;
	scanf("%d.%d.%d", &g1, &s1, &k1);
	scanf("%d.%d.%d", &g2, &s2, &k2);
	long long  count1 = g1 * 17 * 29 + s1 * 29 + k1;
	long long  count2 = g2 * 17 * 29 + s2 * 29 + k2;
	bool under_0 = true;
	long long subtract = count2 - count1;  //实付-应付
	if(count1 - count2 < 0)
		under_0 = false;
	if(subtract < 0)	subtract = -1 * subtract;
	int g,s,k;
	k = subtract % 29;
	s = subtract / 29 % 17;
	g = subtract / 29 /17;
	if(!k && !s && !g) //就是0.0.0
        k = k;
    else if(under_0)
		printf("-");
	printf("%d.%d.%d\n", g, s, k);
	return 0;
}
