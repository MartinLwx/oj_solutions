#include<bits/stdc++.h>
using namespace std;
int seq[1010];
stack<int> s;
int main()
{
	int capacity, length, query;
	scanf("%d%d%d", &capacity, &length, &query);
	while(query--){
		while(!s.empty())	s.pop();
		for(int i=1;i<=length;i++)	scanf("%d", &seq[i]);	//存储序列
		int cur = 1;	//待出栈元素在序列里的位置
		bool success = true;
		for(int i=1;i<=length;i++){
			s.push(i);
			if(s.size() > capacity){
				success = false;
				break;
			}
			while(!s.empty() && s.top() == seq[cur]){	//反复检查待出栈元素是否等于栈顶元素
				s.pop();
				cur++;
			}
		}
		if(s.empty() && success)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
