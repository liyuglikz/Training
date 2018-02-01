#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a < b ? a : b)
char ans[][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
vector<char> lib;
int flag;

bool judgec(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool judge( char c )
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' || c <= '9');
}

int func_time( char c)
{
	if( c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if(c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c - 'a') + 10;
}

int func_day( char c)
{
	if(c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c - 'a');
}

void cmp( char *s1, char *s2)
{
	int l1(strlen(s1)), l2(strlen(s2));
	int l(MIN(l1, l2));
	for(int i = 0; i < l; ++i)
	{
		if( *(s1 + i) == *(s2 + i))
		{
			if( flag == 0 && judgec( *(s1 + i)) )
			{
				lib.push_back( *(s1 + i) );
				++flag;
			}
			else if(flag > 0 &&  judge( *(s1 + i) ) )
				lib.push_back( *(s1 + i) );
		}
	}
}

int cmp2( char *s1, char *s2)
{
	int l1(strlen(s1)), l2(strlen(s2));
	int l(MIN(l1, l2));
	for(int i = 0; i < l; ++i)
	{
		if( (*(s1 + i) == *(s2 + i))  && judgec( *(s1 + i)))
		{
			return i;
		} 
	}
}

char s1[100], s2[100];

int main()
{
	scanf("%s%s", s1, s2);
	cmp(s1, s2);
	scanf("%s%s", s1, s2);
	printf("%s", ans[ func_day( lib[0])]);
	printf(" ");
	printf("%02d:%02d\n", func_time(lib[1]), cmp2(s1, s2));
}
