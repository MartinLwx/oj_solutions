#include<bits/stdc++.h>
using namespace std;
int main()
{
	string right, wrong;
	cin >> right;
	cin >> wrong;

	string ans = "";
	for(int i=0;i<right.size();i++)
	{
		bool f = true;
		for(int j=0;j<wrong.size();j++)
			if(right[i] == wrong[j])
				f = false;
		if(f)    //说明没找到
		{
			char ch = toupper(right[i]);
			bool exist = false;
			for(int k=0;k<ans.size();k++)
				if(ch == ans[k])
					exist = true;
			if(!exist)
				ans += ch;
		}
	}
	cout << ans;
    return 0;
}
