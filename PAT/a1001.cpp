#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	int ans = a + b;
	if(ans / 1000 == 0)		//只有3位
		cout << ans;
	else
	{
		vector<char> v;
		int cnt = 0;
		int t;
		char tmp;
		if(ans < 0)
        {
        	cout << '-';
        	ans = -ans;
        }
		while(ans)
		{
			t = ans % 10;
            tmp = t + '0';
			v.push_back(tmp);
			ans /= 10;
			cnt++;
			if(cnt == 3 && ans)
			{
				v.push_back(',');
				cnt = 0;
			}
		}
		for(int i=v.size()-1;i>=0;i--)
			cout << v[i];
	}
	return 0;
}

