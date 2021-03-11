#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	std::vector<int> v;

	int tmp;
	for(int i=0;i<n;i++)
	{
	    v.clear();
		for(int j=0;j<n;j++)
		{
			cin >> tmp;
			if(tmp>=0 && tmp<=m)
				v.push_back(tmp);
		}

		// 读完一行了
		sort(v.begin()+1,v.end());   //不包括老师
		//for(int j=0;j<v.size();j++) cout << v[j] << " "; cout<<endl;
		double ans = 0.0;
		for(int j=2;j<v.size()-1;j++)
			ans += v[j];
        //cout << ans << endl;
		ans /= (v.size() - 3);
		ans = (v[0] + ans) / 2.0;
		cout << round(ans) << endl;
	}
    return 0;
}
