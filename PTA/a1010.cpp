#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll char2int[256];
const ll INF = (1LL << 63) - 1; // 都用到了字符'z'了，说明radix可以很大
void init()
{
	for(char c='0';c<='9';c++)
		char2int[c] = c - '0';
	for(char c='a';c<='z';c++)
		char2int[c] = c - 'a' + 10;
}

ll convert10(string s, ll radix, ll inf)
{
	ll ans = 0;
	for(int i=0;i<s.size();i++)
	{
		ans = ans * radix + char2int[s[i]];
		if(ans < 0 || ans > inf)	return -1;
	}
	return ans;
}

int find_lowest(string s)
{
	int ans = -1;
	for(int i=0;i<s.size();i++)
		if(char2int[s[i]] > ans)
			ans = char2int[s[i]];
	return ans + 1;   //10进制为例，最大数字为9
}

int cmp(string s, ll radix, ll value)
{
	ll num = convert10(s, radix, value); // 将N2转换为10进制
	if(num < 0)		return 1;   //溢出了，说明肯定是N2 > value
	if(value > num)		return -1;  //value较大
	else if(value == num) return 0; //相等
	else return 1; //num较大
}

ll binary_search(string s, ll l, ll r, ll t)
{
	ll mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		int flag = cmp(s, mid, t);
		if(flag == 0)	return mid;
		else if(flag == -1)	 l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main()
{
    init();
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if(tag == 2)
		swap(n1,n2);   //让radix始终为N1的进制

	ll value = convert10(n1, radix, INF);  //根据radix转换N1为十进制
	ll low = find_lowest(n2);   //根据N2所用的字符串，我们可以确定N2进制的下界
	ll high = max(low, value) + 1;
	ll ans = binary_search(n2, low, high, value);
	if(ans == -1)
		cout << "Impossible" << endl;
	else
		cout << ans;
	return 0;
}
