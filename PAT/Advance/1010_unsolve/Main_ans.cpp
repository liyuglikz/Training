#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const long long int MAXN = 32;
const long long int RADIX_MAX = 1e8 + 5;

long long int MAX( long long int a, long long int b)
{
	return a > b ? a : b;
}

long long int trans( char s[], long long int radix)//将radix进制数 s 转为十进制数
{
	long long int num = 0;
	int len = strlen(s);
	for(int i = 0; i < len; ++i)
	{
		num *= radix;
		if( '0' <= s[i] && s[i] <= '9')
			num += ( s[i] - '0');
		else
			num += ( s[i] - 'a' + 10);
	}
	return num;
}

long long int solve( char num1[], char num2[], long long int radix) // 求使num1 = num2(radix) 的进制，已知num2的进制，若没有则返回-1
{
	int radix_min = 1;

	long long int k1 = 0;
	long long int k2 = trans( num2, radix);

	if( *num1 == *num2 && *num1 == '0')
		return 1;
	if( *num1 != *num2 && *num1 == '0')
		return -1;

	for(char *p = num1; *p; ++p)
	{
		if( '0' <= *p && *p <= '9')
			radix_min = MAX( radix_min, (long long int)(*p - '0'));
		else
			radix_min = MAX( radix_min, (long long int)(*p - 'a' + 10));
	}

	for(int i = radix_min + 1; i <= RADIX_MAX; ++i)
	{
		k1 = trans( num1, i);
		if( k1 == k2)
			return i;
		else if( k1 > k2 )
			return -1;
	}
	return -1;
}

int main()
{
	char num1[MAXN];
	char num2[MAXN];
	long long int tag;	//tag = 1: Radix(num1) = radix; tag = 2: Radix(num2) = radix
	long long int radix;

	while( scanf("%s %s %lld %lld", num1, num2, &tag, &radix) == 4)
	{
		if( tag - 1)
			radix = solve( num1, num2, radix);
		else
			radix = solve( num2, num1, radix);

		if (radix != -1)
			printf("%lld\n", radix);
		else
			puts("Impossible");
	}

	return 0;
}
