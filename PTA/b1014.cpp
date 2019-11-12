#include<bits/stdc++.h>
using namespace std;
char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	int i;
	for(i=0;i<a.size() && i<b.size();i++)
	{
		if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G')
		{
			cout << week[a[i] - 'A'] << " ";
			break;
		}
	}
	for(i++;i<a.size() && i<b.size();i++)
	{
		if(a[i] == b[i])
		{
			if(isdigit(a[i]))
            {
                printf("%02d:", a[i] - '0');
                break;
            }
            else if(a[i] >= 'A' && a[i] <= 'N')
            {
                //cout << a[i] <<endl;
                printf("%02d:", a[i] - 'A' + 10);
                break;
            }
		}
	}
	for(i=0;i<c.size() && i<d.size();i++)
	{
		if(c[i] == d[i])
			if(isalpha(c[i]))
			{
				printf("%02d\n", i);
				break;
			}
	}
	return 0;
}
