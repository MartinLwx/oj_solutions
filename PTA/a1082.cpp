#include<bits/stdc++.h>
using namespace std;
char number[15][6] = {"ling", "yi", "er", "san", "si",
				 "wu", "liu", "qi", "ba", "jiu"};
char q[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};


int main()
{
	string s;
	cin >> s;
	int l = 0, r = s.size() - 1;
	if(s[0] == '-')
	{
		cout << "Fu";
		l++;
	}
	while(l + 4 <= r)	r -= 4;			//数字分成a,b,c三段，先定位到最高的一段
	while(l < s.size())
	{
		bool acum0 = false;		//累加0
		bool printed = false;	//是否有输出过
		while(l <= r)
		{
			if(l > 0 && s[l] == '0')	acum0 = true;   
			else
			{ //当前位不为0
				if(acum0)    //存在累计的0
				{
					cout << " ling";
					acum0 = false;
				}
				if(l > 0)	cout << " ";    //非首位的话后面都要输出空格
				cout << number[s[l] - '0'];    //输出对应数字
				printed = true;    // >=1的数字被输出
				if(l != r)  //因为r始终在每一段的最后一位，如果不相等说明不是各位，那么就要输出对应的百十千
					cout << " " << q[r - l - 1];
			}
			l++;    //处理完当前位，进行下一位
		}
		if(printed && r != s.size() - 1)   //非个位就输出万或亿
			cout << " " << q[(s.size() - 1 - r) / 4 + 2];
		r += 4;
	}

	return 0;
}

