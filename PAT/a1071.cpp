#include<bits/stdc++.h>
using namespace std;
map<string, int> word_list;
int main()
{
	char c;
	string tmp = "";
	while(~scanf("%c", &c))
	{
		if(isalpha(c) || isdigit(c))
        {
            if(isupper(c))  c = tolower(c);		// 大小写不敏感，所以是按照小写存储
            tmp += c;
        }
		else
		{	
		    if(tmp != "")	// 遇到连续的非字母/数字字符串就会是空字符串，不统计空字符串
                if(word_list.count(tmp) == 0)
                    word_list[tmp] = 1;
                else
                    word_list[tmp]++;
			tmp = "";
		}
	}
	int max_num = 0;
	string ans;
	map<string, int>::iterator it;
	for(it=word_list.begin();it!=word_list.end();it++)		// 找出出现次数最多的
	{
		if(it->second > max_num)
		{
			max_num = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << max_num;
	return 0;
}
