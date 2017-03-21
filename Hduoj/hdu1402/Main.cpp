#include <iostream>
#include <string>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const double pi = acos(-1);
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;
const double eps = 1e-5;

class Complex
{
public:
	double r, v;

	Complex(){}
	Complex(double a, double b) : r(a), v(b){}

	Complex operator + (const Complex &k)
	{	return Complex( r + k.r, v + k.v);}

	Complex operator - (const Complex &k)
	{	return Complex( r - k.r, v - k.v);}

	Complex operator * (const Complex &k)
	{	return Complex( r * k.r - v * k.v, r * k.v + v * k.r);}
};

void rader(Complex T[], int len)
{
	int i, j, k, l = len - 1;
	for(i = 1, j = len >> 1; i < l; ++i)
	{
		if(i < j)
			swap( T[i], T[j]);
		k = len >> 1;

		while(j >= k)
		{
			j -= k;
			k >>= 1;
		}
		if(j < k) j += k;
	}
}

int FFT( Complex T[], int len, int flag)
{
	rader(T, len);

	int i, j, k, l;

	for(i = 2; i <= len; i <<= 1)
	{
		Complex w( cos( flag * -2 * pi / i), sin( flag * -2 * pi / i));
		for(j = 0; j < len; j += i)
		{
			l = i >> 1;
			Complex wn(1, 0);
			for(k = 0; k < l; ++k)
			{
				Complex left = T[j + k];
				Complex right = T[j + k + l] * wn;

				T[j + k] = left + right;
				T[j + k + l] = left - right;

				wn = wn * w;
			}
		}
	}

	if(-1 == flag)
	{
		for(i = 0; i < len; ++i)
		{
			T[i].r /= len;
		}
	}
}

void gr(Complex a[], Complex b[],  int len)
{
	FFT (a, len, 1);
	FFT (b, len, 1);
	for (int i = 0; i < len; ++i)
		a[i] = a[i] * b[i];
	FFT (a, len, -1);
}

int getM(int len)
{
	int ans = 1;	
	while(len)
	{
		ans <<= 1;
		len >>= 1;
	}
	return ans;
}

void longer(Complex k[], int len, int len2)
{
	for(int i = len; i < len2; ++i)
		k[i].r = k[i].v = 0;	
}

char s1[MAXM], s2[MAXM];
Complex A[MAXM], B[MAXM];

int answer[MAXM];

void solve()
{
	while( ~scanf("%s%s", s1, s2) )
	{
		int len = 0, l1 = 0, l2 = 0;
		int a = 0, b = 0;
		int len1 = strlen( s1 ), len2 = strlen( s2 );

		while(s1[a] == '0' && s1[a + 1] != '\0')
			++a;

		for(int i = a; i < len1; ++i)
		{
			A[l1].r = s1[i] - '0';
			A[l1].v = 0;
			++l1;
		}
		
		while(s2[b] == '0' && s2[b + 1] != '\0')
			++b;

		for(int i = b; i < len2; ++i)
		{
			B[l2].r = s2[i] - '0';
			B[l2].v = 0;
			++l2;
		}

		len = getM( l1 + l2 - 1);

		longer( A, l1, len);
		longer( B, l2, len);


		gr(A, B, len);

		for(int i = 0; i < len; ++i)
		{
			answer[i] = ((int)(A[i].r + eps));
		}


		for(int i = len - 1; i >= 0; --i)
		{
			answer[i] += a;
			a = answer[i] / 10;
			answer[i] %= 10;
		}

		b = 0;
		if(a)
		{
			s1[b++] = a + '0';
		}

		for(int i = 0; i < l1 + l2 - 1; ++i)
		{
			s1[b++] = answer[i] + '0';
		}
		
		a = 0;
		while( s1[a] == '0' && s1[a + 1] != '\0')
			++a;
	
		puts( s1 + a );
	}
}

int main()
{
	solve();
	return 0;
}
