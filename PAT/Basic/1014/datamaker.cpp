#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;
const int MAXL = 60;
char s1[MAXN], s2[MAXN];

char getC()
{
	return 'A' + (rand() % 26);
}

void output()
{
	srand( (unsigned int) time(NULL));
	for(int i = 0; i < MAXL; ++i)
	{
		s1[i] = getC();		
		s2[i] = getC();
	}
	s1[MAXL] = s2[MAXL] = 0;
	puts(s1);
	puts(s2);

}

int main()
{
	output();
	output();
	return 0;
}
