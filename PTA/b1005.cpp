#include<bits/stdc++.h>
using namespace std;
int vis[110] = {0};
int main()
{
    int n;
    cin >> n;
    int len = n;
    int t;
    while(n--)
    {
        cin >> t;
        vis[t] = true;
    }
    for(int i=1;i<101;i++)
    {
        if(vis[i])    //˵������
        {
            for(int j=i;j>1;)
            {
                if(j%2==0)    j /= 2;
                else          j = (3*j + 1)/2;
                if(j <=100 && vis[j])   //�и�С������
                {
                    vis[j] = false;
                    len--;
                    if(j < i) break; //֮ǰ������
                }
            }
        }
    }
    for(int i=100;i>1;i--)
    {
        if(vis[i])
        {
            if(len == 0) break;
            len == 1 ?
            cout << i : cout<< i << " ";
            len--;
        }
    }

    return 0;
}
