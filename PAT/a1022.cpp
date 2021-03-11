#include<bits/stdc++.h>
using namespace std;
map<string, set<int>> titles, authors, key_words, publishers, publisher_years;
void query(map<string, set<int>> &m, string pat)
{
	if(m.count(pat) == 0)
		cout << "Not Found" << endl;
	else
	{
		set<int>::iterator it;
		for(it=m[pat].begin();it!=m[pat].end();it++)
			printf("%07d\n", *it);
	}
}	// 根据指定的map容器和字符串进行查找，有的话就输出
int main()
{
	int books;
	cin >> books;
	getchar();

	int id;
	string tmp;
	for(int i=0;i<books;i++)
	{
		cin >> id;
		getchar();
		// 分别处理书籍的各个信息，将其和对应的ID关联起来
		getline(cin, tmp);
		titles[tmp].insert(id);
		getline(cin, tmp);
		authors[tmp].insert(id);
		while(cin >> tmp)
		{
			key_words[tmp].insert(id);
			char ch = getchar();
			if(ch == '\n')	break;
		}
		getline(cin, tmp);
		publishers[tmp].insert(id);
		getline(cin, tmp);
		publisher_years[tmp].insert(id);
	}

	int queries;
	cin >> queries;
	int num;
	string pat;
	for(int i=0;i<queries;i++)
	{
		scanf("%d: ", &num);
		getline(cin, pat);
		cout << num << ": " << pat << endl;
		switch(num)		// 根据不同类型的信息去不同的map里面查询
		{
			case 1 : query(titles, pat);	break;
			case 2 : query(authors, pat);	break;
			case 3 : query(key_words, pat);	break;
			case 4 : query(publishers, pat);	break;
			case 5 : query(publisher_years, pat);	break;
			default:	break;
		}
	}
	return 0;
}
