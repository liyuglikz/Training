#include <iostream>
#include <algorithm>
#include <string>

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <map>

using namespace std;
const int MAXL = 16;

char s_t[MAXL];
char s_t2[MAXL];
char s_o[MAXL];
char s_n[MAXL];

map<string, double> mps;

void init()
{
	mps["UTC"]	=	0;
	mps["GMT"]	=	0;
	mps["BST"]	=	1;
	mps["IST"]	=	1;
	mps["WET"]	=	0;
	mps["WEST"]	=	1;
	mps["CET"]	=	1;
	mps["CEST"]	=	2;
	mps["EET"]	=	-2;
	mps["EEST"]	=	3;
	mps["MSK"]	=	3;
	mps["MSD"]	=	4;
	mps["AST"]	=	-4;
	mps["ADT"]	=	-3;
	mps["NST"]	=	-3.5;
	mps["NDT"]	=	-2.5;
	mps["EST"]	=	-5;
	mps["EDT"]	=	-4;
	mps["CST"]	=	-6;
	mps["CDT"]	=	-5;
	mps["MST"]	=	-7;
	mps["MDT"]	=	-6;
	mps["PST"]	=	-8;
	mps["PDT"]	=	-7;
	mps["HST"]	=	-10;
	mps["AKST"]	=	-9;
	mps["AKDT"]	=	-8;
	mps["AEST"]	=	10;
	mps["AEDT"]	=	11;
	mps["ACST"]	=	9.5;
	mps["ACDT"]	=	10.5;
	mps["AWST"]	=	8;
}

void input()
{
	scanf("%s", s_t);
	if( strcmp( s_t, "noon") == 0)
	{
		strcpy( s_t, "12:00");
		strcpy( s_t2,"p.m.");
	}
	else if( strcmp( s_t, "midnight") == 0)
	{
		strcpy( s_t, "12:00");
		strcpy( s_t2,"a.m.");
	}
	else
	{
		scanf("%s", s_t2);
	}

	scanf("%s", s_o);
	scanf("%s", s_n);
}

void output()
{
	if( strcmp ( s_t, "12:00") == 0)
	{
		if( strcmp( s_t2, "p.m.") == 0)
			puts("midnight");
		else
			puts("noon");
	}
	else
		printf("%s %s\n", s_t, s_t2);
}

bool flag;

void solve()
{
	double k;
	int hour;
	int min;

	flag = (strcmp( s_t2, "a.m.") == 0);

	sscanf(s_t, "%d:%d", &hour, &min);
	k = hour + ( mps[s_n] - mps[s_o] );
	hour = (int) k;	

	printf("%g = %g - %g %d\n", k, mps[s_n], mps[s_o], flag);

	k = k - hour;
	while( hour > 12 )
	{
		hour -= 12;
		flag = !flag;
	}

	while( hour <= 0)
	{
		hour += 12;
		flag = !flag;
	}

	int mk = k * 60;
	min += mk;

	while( min >= 60)
	{
		min -= 60;
		++hour;
		while( hour > 12 )
		{
			hour -= 12;
			flag = !flag;
		}
	}
	while( min < 0 )
	{
		min += 60;
		--hour;
		while( hour <= 0)
		{
			hour += 12;
			flag = !flag;
		}
	}

	if(hour == 12)
		flag = !flag;

//	printf("%g = %g - %g %d\n", k, mps[s_n], mps[s_o], flag);
	sprintf( s_t, "%d:%02d", hour, min);
	strcpy ( s_t2, flag ? "a.m." : "p.m.");
}

int main()
{
	init();

	int T;
	scanf("%d", &T);
	while( T-- )
	{
		input();
		solve();
		output();
	}
	return 0;
}
