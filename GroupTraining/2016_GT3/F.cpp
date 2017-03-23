#include <bits/stdc++.h>
#define EX(a, b) (a = a ^ b, b = a ^ b, a = a ^ b)
using namespace std;
const int MAXN = 1e2 + 5;
const int TimeLimit = 1e6;
const int MemoryLimit = 1e5;
const int NOW = 28;

char maps[MAXN][MAXN];

int go[][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int direct_now;

int _register [30], buff[30], buff_now;
int x_now, y_now;
int run_time;
bool _status;

void func(char cmd)
{
	if(cmd == '!')	
	{
		printf("%d\n", _register[NOW]);
	}
	else if(cmd == '?')
	{
		_register[NOW] = buff[ buff_now++ ]; 
	}
	else if(cmd == '+')
	{
		++_register[NOW];
		if(_register[NOW] > MemoryLimit)
			_status = true;
	}
	else if(cmd == '-')
	{
		--_register[NOW];
		if(_register[NOW] < -MemoryLimit)
			_status = true;
	}
	else if(cmd >= 'A' && cmd <= 'Z')
	{
		EX( _register[NOW], _register[ cmd - 'A']);		
	}
	else if(cmd == '^')
	{
		direct_now = 0;
	}
	else if(cmd == '>')
	{
		direct_now = 1;
	}
	else if(cmd == 'v')
	{
		direct_now = 2;
	}
	else if(cmd == '<')
	{
		direct_now = 3;
	}
	else if(cmd == '@')
	{
		direct_now = (direct_now + 3) % 4;
		if(_register[NOW])
			direct_now = (direct_now + 2) % 4;
	}
}

void solve()
{
	int h, w, n;
	while(scanf("%d%d", &h, &w) == 2)
	{
		memset(_register, 0, sizeof(_register));

		for(int i = 1; i <= h; ++i)
			scanf("%s", maps[i] + 1);
		scanf("%d", &n);

		for(int i = 1; i <= n; ++i)
			scanf("%d", buff + i);

		buff_now = 1;

		x_now = 1;
		y_now = 1;
		direct_now = 1;
		run_time = 0;
		_status = false;

		while( maps[x_now][y_now] != '#')
		{
			++run_time;
			//printf("(%d %d) %c\n", x_now, y_now, maps[x_now][y_now]);
			func( maps[x_now][y_now] );

			if(buff_now > n)
				buff_now = n;

			x_now += go[ direct_now ][0];
			y_now += go[ direct_now ][1];

			if(_status)
			{
				puts("OVERFLOW ERROR");
				break;
			}

			if(x_now < 1 || x_now > h || y_now < 1 || y_now > w)
			{
				puts("RUNTIME ERROR");
				break;
			}

			if(run_time > TimeLimit)
			{
				puts("TIME LIMIT EXCEEDED");
				break;
			}
		}
	}
}

int main()
{
	solve();
	return 0;
}
