#include<bits/stdc++.h>
using namespace std;
char a[10100];
int main()
{
	bool negtive = true;
	char ch;
	int t;

	cin >> ch;
	if(ch == '+')	negtive = false;	  //定正负
	std::vector<char> v;  //存放了除了小数点的E前的所有数字

	while(cin>>ch)
	{
		if(ch == 'E')
			break;
        if(ch != '.')
            v.push_back(ch);
	}  
	cin >> ch;
	bool exp_neg = false;
	if(ch == '-')   exp_neg = true;

	int exp = 0;
	while(cin>>ch)
	{
		exp = exp * 10 + (ch - '0');
	}  //得到指数
	if(!exp_neg)   //如果指数为正
	{
		if(negtive)
			cout << "-";
		if(exp > v.size() - 1)
		{
		    for(int i=0;i<v.size();i++)
                cout << v[i];
            for(int i=0;i<exp-v.size()+1;i++)
                cout <<"0";   //指数比较大，可以忽略小数点的情况
		}else
		{
		    cout << v[0];
		    for(int i=1;i<v.size();i++)
            {
                if(i - 1 == exp)
                    cout << ".";
                cout << v[i];
            }
		}    //比如1.21E+00，此时指数尚不能大得忽略掉小数点
	}else   //指数为负
	{
		if(negtive)
			cout << "-";
		cout << "0.";
		for(int i=0;i<exp-1;i++)
			cout << "0";
		for(int i=0;i<v.size();i++)
			cout << v[i];
	}
	return 0;
}

