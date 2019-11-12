#include<bits/stdc++.h>
using namespace std;
struct student
{
	char name[20];
	char gender;
	char id[20];
	int grade;
}female_high, male_low;

void Init()
{
	female_high.grade = -1;
	male_low.grade = 110;
}

bool higher(student a, student b)
{
	return a.grade > b.grade;
}

int main()
{
	int n;
	Init();
	scanf("%d", &n);
	student tmp;
	while(n--)
	{
		scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.grade);
		if(tmp.gender == 'M' && higher(male_low, tmp))
			male_low = tmp;
		if(tmp.gender == 'F' && higher(tmp, female_high))
			female_high = tmp;
	}

	bool absent = false;
	if(female_high.grade == -1)
	{
		printf("Absent\n");
		absent = true;
	}else printf("%s %s\n", female_high.name, female_high.id);
	if(male_low.grade == 110)
	{
		printf("Absent\n");
		absent = true;
	}else printf("%s %s\n", male_low.name, male_low.id);
	if(absent)
		printf("NA");
	else printf("%d", female_high.grade - male_low.grade);
	return 0;
}
