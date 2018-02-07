#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
char c[MAXN], Q[MAXN];
int  B, R;

int main()
{
	scanf("%s%d", c, &B);
	int l = strlen( c ), k, len = 0;
	for(int i = 0; i < l; ++i)
	{
		k = c[i] - '0';	
		R = R * 10 + k;
		if( R >= B)
		{
			Q[len++] = (R / B) + '0';		
			R = R % B;
		}
		else
			Q[len++] = '0';
	}
	char *p = Q;
	while( *p == '0' && *p && len > 1)
		++p;
	printf("%s %d\n", p, R);

	return 0;
}
