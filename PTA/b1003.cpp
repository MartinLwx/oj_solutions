#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
    getchar();    //处理换行符
	for(int j=0;j<n;j++)
    {
		getline(cin, s);
		int cnt_p = 0, cnt_t = 0, others = 0;	//P的个数，T的个数，除了PTA字符外的字符的个数
		int pos_p = -1, pos_t = -1;		//P的最后一个字符的位置， T的最后一个字符的位置
		for(int i=0;i<s.size();i++)
		{
			if(s[i] == 'P')
			{
				cnt_p++;
				pos_p = i;
			}else if(s[i] == 'T')
			{
				cnt_t++;
				pos_t = i;
			}else if(s[i] != 'A') others++;
		}

		//检验条件1：只能包含PTA三种字符，而且中间不为空
		if( (cnt_p != 1) || (cnt_t != 1) || (others != 0) || (pos_t - pos_p <= 1))
		{
			cout << "NO" << endl;
			continue;
		}

		//xPyTz, x、y、z都是个数
		//每经过一次条件3的变化，就要y+1, z+x
		int x = pos_p, y = pos_t - pos_p - 1, z = s.size() - pos_t - 1;

		//条件3都是由条件2变化而来，这是逆推的过程，根据"PT"之间不能有空格，从而是倒推y-1次
		if(z - x * (y-1) == x)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
