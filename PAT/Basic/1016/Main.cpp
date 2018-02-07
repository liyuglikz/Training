#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll func( ll A, ll Da)
{
	ll k = 0;
	while( A )
	{
		if( (A % 10) == Da)
		{
			k *= 10;	
			k += Da;
		}
		A /= 10;
	}
	return k;
}

int main()
{
	ll A, B, Da, Db, Pa, Pb;
	cin >> A >> Da >> B >> Db;
	Pa = func( A, Da );
	Pb = func( B, Db );
	cout << Pa + Pb << endl;
	return 0;
}
