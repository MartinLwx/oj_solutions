#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	int t;
	cin >> t;

	int cnt = 1;
	while(t--)
	{
		cin >> a >> b >> c;
		if(a + b > c)
			cout << "Case #" << cnt << ": true" << endl;
		else
			cout << "Case #" << cnt << ": false" << endl;
        cnt++;
	}
    return 0;
}
