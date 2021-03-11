#include<bits/stdc++.h>
using namespace std;
int a[4];
int arr_num(int a[])
{
	int value = 0;
	for(int i=0;i<4;i++)
		value = value * 10 + a[i];
	return value;
}	//数组->数字

bool cmp(int x, int y)
{
    return x > y;
}
void re_set_a(int x, int a[])
{
    for(int i=0;i<4;i++)
    {
        a[i] = x % 10;
        x /= 10;
    }
}	//数字->数组。反正后面都是要排序的，这里a[0]表示最高位或最低位并没有差别
int main()
{
    int n;
    cin >> n;
    int ans = n;
    while(true)
    {
	    re_set_a(ans, a);
	    sort(a, a+4);
		int low = arr_num(a);
		sort(a, a+4, cmp);
		int high = arr_num(a);
		ans = high - low;
		printf("%04d - %04d = %04d", high, low, ans);	//用printf控制输出比较方便
        if(ans == 6174 || ans == 0)
            break;
        else
            cout << endl;
    }
	return 0;
}
