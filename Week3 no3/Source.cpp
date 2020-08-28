#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<cctype>
#include<string.h>
struct people{                //<--------------------------------Stuct!
	char nickname[10];
	int graderscore;
};
void sortScore(struct people* p,int n)  //<--------------------Self created Function
{
	char temp[10];
	int temp1;
	for (int i = 0; i < n-1; i++)           //<------------------Nested loop
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (p[j].graderscore < p[j+1].graderscore)
			{
				strcpy(temp, p[j].nickname);
				strcpy(p[j].nickname, p[j + 1].nickname);
				strcpy(p[j + 1].nickname, temp);
				temp1 = p[j].graderscore;
				p[j].graderscore = p[j + 1].graderscore;
				p[j + 1].graderscore = temp1;
			}
		}
	}
}
const char* checkGrade(struct people* p, int n)
{
	int i = 0;
	for (i = 0; i < n;i++)
	{
		if (p[i].graderscore >= 80 && p[i].graderscore <= 100)       //<------------Expression And Or
			return "A";
		else if (p[i].graderscore >= 75 && p[i].graderscore <= 79)
		{
			return "B+";
		}
		else if (p[i].graderscore >= 70 && p[i].graderscore <= 74)
			return "B";
		else if (p[i].graderscore >= 65 && p[i].graderscore <= 69)
		{
			return "C+";
		}
		else if (p[i].graderscore >= 60 && p[i].graderscore <= 64)
			return "C";
		else if (p[i].graderscore >= 55 && p[i].graderscore <= 59)
		{
			return "D+";
		}
		else if (p[i].graderscore >= 50 && p[i].graderscore <= 54)
			return "D";
		else return "F";
	}
}
int main() {
	int n;
	struct people* p;           //<------------ Pointer to array of struct
	scanf("%d", &n);
	if (n < 1)
	{
		printf("ERROR");
		return 0;
	}
	p = (people*)malloc(n * sizeof(struct people));
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", p[i].nickname,&p[i].graderscore);
		if (p[i].graderscore < 0 || p[i].graderscore>100)
		{
			printf("Error");
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		p[i].nickname[0] = toupper(p[i].nickname[0]);
	}
	sortScore(p, n);
	checkGrade(p, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d : %s %d %s\n", i, p[i-1].nickname, p[i-1].graderscore,checkGrade(p,n));
	}
	return 0;
}