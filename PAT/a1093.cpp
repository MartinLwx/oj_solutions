#include<bits/stdc++.h>
using namespace std;     //设当前位置为i，字符段长度为len
int lp[100010] = {0};  	//区间[0,i]的P的个数
int rt[100010] = {0};   //区间[i,len-1]的T的个数
const int MOD = 1000000007;

int main()
{
	string pat;
	getline(cin, pat);
	for(int i=0;i<pat.size();i++)
		if(pat[i] == 'P')
			lp[i] = lp[i-1] + 1;
		else
			lp[i] = lp[i-1];		//数P
	for(int i=pat.size()-1;i>=0;i--)
		if(pat[i] == 'T')
			rt[i] = rt[i+1] + 1;
		else
			rt[i] = rt[i+1];		//数T
    int ans = 0;
    for(int i=0;i<pat.size();i++)
        if(pat[i] == 'A')
            ans = (ans + lp[i] * rt[i]) % MOD;    //在每个A的位置让两边的可能相乘就得到了经过当前位置A会有多少个PAT，累加起来就是答案
    cout << ans;
	return 0;
}
