#include<bits/stdc++.h>
using namespace std;
int get_height(int x)
{
	for(int i=0;;i++)
	{
		int star_cnt = 2*i*i + 4*i + 1;
		if(star_cnt > x)
			return i-1;
	}
}
int main()
{
	int all;
	char ch;
	cin >> all;
	getchar();
	cin >> ch;
    if(all == 0)
    {
        cout << 0;
        return 0;
    }
	int height = get_height(all);
	int longest_star = 2*height + 1;
	for(int i=1;i<=height;i++)
	{
		for(int j=2;j<=i;j++) cout << " ";
		for(int k=1;k<=longest_star;k++)	cout << ch;
		longest_star -= 2;   //为2的等差数列
		cout << endl;
	}

	longest_star = 2*height + 1;
	for(int i=1;i<=(longest_star-1)/2;i++)	cout << " ";
	cout << ch << endl;

    longest_star  = 3;
	for(int i=height;i>=1;i--)
	{
		for(int j=2;j<=i;j++) cout << " ";
		for(int k=1;k<=longest_star;k++)	cout << ch;
		longest_star += 2;   //为2的等差数列
		cout << endl;
	}
	cout << all - (2*height*height + 4*height + 1);
    return 0;
}
