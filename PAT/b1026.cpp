#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c1,c2;
	cin >> c1 >> c2;
	int ans = round((c2 - c1) / 100.0);
	int ss = ans % 60;
	ans /= 60;
	int mm = ans % 60;
	ans /= 60;
	int hh = ans % 60;
	printf("%02d:%02d:%02d", hh, mm ,ss);
    return 0;
}
