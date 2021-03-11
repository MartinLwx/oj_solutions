#include<bits/stdc++.h>
using namespace std;
int prime[10010];
bool flag[1000000] = {0};
bool isprime(int n){
    if (n <= 1)	return false;
    if (n == 2) return true;
    for(int i=2;i<=sqrt(n);i++)
        if (n%i == 0) return false;
    return true;
}

void getPrime(int n)
{
    int cnt = 0;
	for(int i=2;;i++)
    {
        if(isprime(i))
        {
            prime[++cnt] = i;
            n--;
        }
        if (n==0) break;
    }
}
int main()
{
	int m,n;
	cin >> m >> n;

	int cnt = 0;
	getPrime(n);
	for(int i=m;i<=n;i++)
	{
		cout << prime[i];
		cnt++;
		if(cnt == 10)
        {
            cout << endl;
            cnt = 0;
        }
		if(cnt != 10 && i!=n && cnt != 0)
            cout << " ";
	}
    return 0;
}
