#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    string id;
    int score;
    student(){}
    student(string _name, string _id, int _score): name(_name),id(_id),score(_score){}
}a[100000];

bool cmp(student x, student y)
{
    return x.score >y.score;
}

int main()
{
    int n;
    cin >> n;
    int len = 0;
    string q,w;
    int tmp;
    while(n--)
    {
        cin >> q >> w >> tmp;
        a[len++] = student(q,w,tmp);
    }
    sort(a, a+len, cmp);
    cout << a[0].name << " " << a[0].id <<endl;
    cout << a[len-1].name << " "<<a[len-1].id << endl;
    return 0;
}
