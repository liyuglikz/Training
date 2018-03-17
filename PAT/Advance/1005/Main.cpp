#include <bits/stdc++.h>

using namespace std;

char num[][12] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char s[105];
int sum;

int main()
{
	cin >> s;
	for(char *p = s; *p; ++p)
		sum += (*p - '0');
	sprintf( s, "%d", sum);
	for( char *p = s; *p; ++p)
	{
		if( p != s)
			putchar(' ');
		printf("%s", num[*p - '0']);
	}
	return 0;
}
