#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int bai = n / 100;
    int shi = (n % 100) / 10;
    int ge = n % 10;
    string ans = "";
    if(bai!=0)
    {
        while(bai--) ans += "B";
    }
    if(shi!=0)
    {
        while(shi--) ans += "S";
    }
    if(ge!=0)
    {
        for(int i=1;i<=ge;i++)
            ans += to_string(i);
    }
    cout << ans;
    return 0;
}
