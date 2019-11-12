#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int n;
	scanf("%d", &n);

    int tmp;
    v.push_back(0);
	for(int i=0;i<n;i++)
    {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
	sort(v.begin()+1, v.end(), greater<int>());

    int ans = 0;
	for(int i=1;i<v.size();i++)
    {
        if(i < v[i])    ans++;
        else break;
    }
	printf("%d", ans);
	return 0;
}
