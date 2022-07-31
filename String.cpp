#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int tam(char c[]);
void cop(char alvo[], char str[]);
char *cat(char alvo[], char str[]);
char *ncat(char *s1, char *s2, int n);
char *ncat(char *s1, char *s2, int n);
char cmp(char s1[], char s2[]);
char ncmp(char *s1, char *s2, int n);
char *srcp(char *c, char o);
char *srcu(char *c, char o);
void subst(char s[], char c1, char c2);

int main()
{
	char s1[] = "Pao de ";
	char s2[] = "Batata";
	char *s3 = cat(s1, s2);
	char s4[] = "Pao ";
	printf("tam de 1 %d\n",tam(s1));
	printf("tam de 2 %d\n", tam(s2));
	printf("%s\n",s3);
	subst(s3, 'a', 'o');
	printf("%s\n",s3);
	subst(s3, 'o', 'a');
	printf("%s\n", s3);
	char s[500];
	printf("String:");
	scanf("%[^\n]",s);
	printf("%s\n",s);
	printf("%d\n",tam(s));
	system("PAUSE");
	return 0;
}

int tam(char *c)
{
	int tam=0;
	for (int x = 0; c[x] != '\0'; x++)
		tam++;
	return tam;
}

void cop(char *alvo, char *str)
{
	int x;
	for (x = 0; str[x];x++)
		alvo[x] = str[x];
	alvo[x] = 0;
}

void ncop(char *alvo, char *str, int n)
{
	int x;
	for (x = 0; str[x] && n < x; x++)
		alvo[x] = str[x];
	alvo[x] = 0;
}

char *cat(char *alvo, char *str)
{
	int x;
	char *buff = (char*)malloc(tam(alvo) + tam(str) + 1);
	cop(buff, alvo);
	for (x = tam(alvo); x < tam(alvo) + tam(str) + 1; x++)
		buff[x] = str[x - tam(alvo)];
	buff[tam(alvo) + tam(str)] = 0;
	return buff;
}

char *ncat(char *s1, char *s2,int n)
{
	if (n < 0)
		return s1;
	else
	{
		int x;
		char *buff = (char*)malloc(tam(s1) + n + 1);
		cop(buff, s1);
		for (x = tam(s1); x < tam(s1) + n + 1; x++)
			buff[x] = s2[x - tam(s1)];
		buff[tam(s1) + n] = 0;
		return buff;
	}
}

char cmp(char s1[], char s2[])
{
	if (s1[0] == 0 && s2[0] == 0)
		return 1;
	if (s1[0] == 0)
		return 0;
	if (s2[0] == 0)
		return 0;
	if (s1[0] == s2[0])
		return cmp(s1+1,s2+1);
	return 0;
}
char ncmp(char *s1, char *s2, int n)
{
	if (tam(s1) >= n && tam(s2) >= n)
	{
		int x, v = 1;
		for (x = 0; x < n; x++)
		{
			if (s1[x] != s2[x])
			{
				v = 0;
				break;
			}
		}
		return v;
	}
		return 0;
}
char *srcp(char *c, char o)
{ 
	int x;
	char *p=NULL;
	for (x = 0; x < tam(c); x++)
	{
		if (c[x] == o && p == NULL)
			p = &c[x];
	}
	return p;
}
char *srcu(char *c, char o)
{
	int x;
	char *p=NULL;
	for (x = 0; x < tam(c); x++)
	{
		if (c[x] == o)
			p = &c[x];
	}
	return p;
}

void subst(char s[], char c1, char c2)
{
	for (int x = 0; x<tam(s); x++)
		if (s[x] == c1)
			s[x] = c2;
}