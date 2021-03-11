#include<bits/stdc++.h>
using namespace std;
struct student
{
	int id;
	int de;
	int cai;
	student(){}
	student(int _x, int _y, int _z): id(_x),de(_y),cai(_z){}
};

int N, L, H;

int get_class(student x)
{
	if(x.de >= H && x.cai >= H)
		return 1;    //才德全尽，德才总分高到低
	else if(x.de >= H && x.cai < H)
		return 2;    //德胜才，德才总分高到低，但是在才德全尽之后
	else if(x.de < H && x.cai < H && x.de >= x.cai)
		return 3;	 //才德兼亡但有德胜才，按总分
	else if(x.de >= L && x.cai >= L)
		return 4;    //有资格录取，按总分
}


bool cmp(student x, student y)
{
	int c1 = get_class(x);
	int c2 = get_class(y);
	if(c1 != c2)
		return c1 < c2;   //种类不同按种类排序
	else if(x.de + x.cai != y.de + y.cai)
			return x.de + x.cai > y.de + y.cai;
	else if(x.de != y.de)
			return x.de > y.de;
	else return x.id < y.id;
}

int main()
{
	scanf("%d%d%d", &N, &L, &H);
	int id, de, cai;

	vector<student> v;
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d", &id, &de, &cai);
		if(de >= L && cai >= L)
        	v.push_back(student(id,de,cai));
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for(int i=0;i<v.size();i++)
	{
		printf("%d %d %d\n", v[i].id, v[i].de, v[i].cai);
	}

	return 0;
}
