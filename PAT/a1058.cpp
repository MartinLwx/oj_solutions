#include<bits/stdc++.h>
using namespace std;

int main()
{
	int g1, s1, k1;
	int g2, s2, k2;
	cin >> g1 >> s1 >> k1 >> g2 >> s2 >> k2;
	int g, s, k;
	g = g1 + g2;
	s = s1 + s2;
	k = k1 + k2;

	int t = k;
	t = k % 29;
	s += k / 29;
	t = s % 17;
	g += s / 17;
	cout << g << "." << s << "." << k;

	return 0;
}

