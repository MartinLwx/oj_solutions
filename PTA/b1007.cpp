#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool vis[100010] = {0};
int cnt = 0;
void getPrime()
{
    for(int i=2;i<100000;i++)
    {
        if(vis[i]== false)
            for(int j=i+i;j<100000;j+=i)
                vis[j] = true;
    }
    for(int i=2;i<100000;i++)
        if(!vis[i])
        {
            a[cnt++] = i;
            //cout << a[cnt-1] << endl;
        }
}
int main()
{
    int n;
    cin >> n;
    if(n <= 2)
    {
        cout << 0;
        return 0;
    }
    getPrime();
    int i = 0;
    int j = 1;
    int ans = 0;
    while(1)
    {
        if(a[i] > n && a[j] > n)
            break;
        if(a[i] <= n && a[j] <= n)
        {
            if(a[j] - a[i] == 2)
                ans++;
        }
        i++;
        j++;
    }
    cout << ans;
    return 0;
}
