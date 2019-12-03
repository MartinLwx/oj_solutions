#include<bits/stdc++.h>
using namespace std;
struct node
{
    double stock;	 //库存量
	double price;    //表示总价，注意都要用double
}a[1010];
const double EPS = 1e-7;
bool cmp(node x, node y)
{
	double unit_price1 = x.price * 1.0/ x.stock;
	double unit_price2 = y.price * 1.0/ y.stock;
	return unit_price2 + EPS < unit_price1;
}

int main()
{
	int n, d;
	cin >> n >> d;
	for(int i=0;i<n;i++)
		cin >> a[i].stock;
	for(int i=0;i<n;i++)
		cin >> a[i].price;
	sort(a, a+n, cmp);


	double profit = 0.0;
	for(int i=0;i<n;i++)
	{
		if(a[i].stock <= d)    //对应的货物的库存量 <= 需求量，也就是说这种要全卖
        {
            profit += a[i].price;
            d -= a[i].stock;
        }
		else                   //否则就是库存量 > 需求量，卖一些就行
        {
            profit += (a[i].price * 1.0 / a[i].stock) * d;
            break;
        }
	}
	printf("%.2f\n", profit);
	return 0;
}

