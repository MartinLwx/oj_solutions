#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a1 = 0;
    int a2 = 0, f2 = 1;
    int a3 = 0;
    double a4 = 0.0;
    int length_a4 = 0;
    int a5 = -1;
    bool change[6] = {0};
    int tmp;
    while(n--)
    {
        cin >> tmp;
        if(tmp % 5 == 0 && tmp % 2 == 0)
        {
            a1 += tmp;
            change[1] = true;
        }

        if(tmp % 5 == 1)
        {
            a2 += f2*tmp;
            f2 *= -1;
            change[2] = true;
        }

        if(tmp % 5 == 2)
        {
            a3++;
            change[3] = true;
        }

        if(tmp % 5 == 3)
        {
            a4 += tmp * 1.0;
            length_a4++;
            change[4] = true;
        }

        if(tmp % 5 == 4)
        {
            a5 = max(a5, tmp);
            change[5] = true;
        }
    }
    if(!change[1])
        cout << "N ";
    else
        cout << a1 << " ";
    if(!change[2])
        cout << "N ";
    else
        cout << a2 << " ";
    if(!change[3])
        cout << "N ";
    else
        cout << a3 << " ";
    if(!change[4])
        cout << "N ";
    else
        printf("%.1f ",a4/length_a4);
    if(!change[5])
        cout << "N";
    else
        cout << a5;
    return 0;
}