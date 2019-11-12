#include<bits/stdc++.h>
using namespace std;
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int zm[11] = {1,0,-1,9,8,7,6,5,4,3,2};
bool check(string s)
{
	int sum = 0;
	for(int i=0;i<17;i++)
    {
        if(!isdigit(s[i]))
            return false;
        sum += weight[i] * (s[i]-'0');
    }
	int z = sum % 11;

	if(z!=2)
		return zm[z] == s[s.size()-1] - '0';
	else
		return s[s.size()-1] == 'X';
}
int main()
{
	int n;
	cin >> n;
	bool all_right = true;
	while(n--)
	{
		string str;
		cin >> str;
		if(!check(str))
		{
			cout << str << endl;
			all_right = false;
		}
	}
	if(all_right)
	{
		cout << "All passed";
	}
    return 0;
}
