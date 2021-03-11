#include<bits/stdc++.h>
using namespace std;
int main()
{
	string broken;
	string pat;
	getline(cin, broken);
	getline(cin, pat);
	for(int i=0;i<broken.size();i++)
	{
		int ch = broken[i];
		if(ch == '+')   //首先处理上档键坏掉的情况
		{
			for(int j=0;j<pat.size();j++)
				if(isupper(pat[j]))
					pat[j] = '#';
		}else if(isalpha(ch))       //再处理英文字母的情况
		{
		    for(int j=0;j<pat.size();j++)
				if(toupper(pat[j]) == ch)
					pat[j] = '#';
		}else
		{
			for(int j=0;j<pat.size();j++)
				if(pat[j] == ch)
					pat[j] = '#';
		}
	}
	for(int i=0;i<pat.size();i++)
	{
		if(pat[i] != '#')
			cout << pat[i];
	}
	cout << endl;
	return 0;
}

