#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a < b ? a : b)
char ans[][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
vector<char> lib;
int flag;
int A, B, C;

bool judgeC( char c)
{
	return (c >= 'A' && c <= 'G');
}

bool judgec(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool judge( char c )
{
	return (c >= 'A' && c <= 'N') || (c >= '0' && c <= '9');//完全写复杂了QAQ，此处卡住，引以为戒 >.<
}

int func_time( char c)
{
	if( c >= '0' && c <= '9')
		return c - '0';
	return (c - 'A') + 10;
}

int func_day( char c)
{
	return (c - 'A');
}

void cmp( char *s1, char *s2)
{
	int l1(strlen(s1)), l2(strlen(s2));
	int l(MIN(l1, l2));
	for(int i = 0; i < l; ++i)
	{
		if( *(s1 + i) == *(s2 + i))
		{
			if( flag == 0 && judgeC( *(s1 + i)) )
			{
				lib.push_back( *(s1 + i) );
				++flag;
			}
			else if(flag == 1 &&  judge( *(s1 + i) ) )
			{
				lib.push_back( *(s1 + i) );
				++flag;
				return;
			}
			else if(flag == 2 && judgec(*(s1 +i)))
				lib.push_back( (char)i );
		}
	}
}
char s1[100], s2[100];

int main()
{
	flag = 0;
	scanf("%s%s", s1, s2);
	cmp(s1, s2);
	scanf("%s%s", s1, s2);
	cmp(s1, s2);

	printf("%s", ans[ func_day( lib[0])]);
	printf(" ");
	printf("%02d:%02d\n", func_time(lib[1]) % 24, (int) lib[2]);
}
