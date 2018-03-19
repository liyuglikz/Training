#include <cstdio>
#include <cstring>
#include <string>

#include <algorithm>

using namespace std;
const int MAXN = 1e4 + 5;
const int MAX_BUFF = 32;

typedef pair<int, int> Node;// Arrived time & serve time

char buff[MAX_BUFF];

Node customers[MAXN];

class Bank
{
	public:
		const static int MAX_QUE = 101;
		int n;
		int last_time[MAX_QUE];
		Node que[MAX_QUE];
		bool que_flags[MAX_QUE];

		explicit Bank( int a = 0)
		{
			n = a;
			for(int i = 0; i < n; ++i)
				last_time[i] = 8 * 3600;
			memset( que_flags, 0, sizeof(que_flags));
		}

		bool enable()
		{
			for(int i = 0; i < n; ++i)
				if( !que_flags[i])
					return true;
			return false;
		}

		void push( Node customer)
		{
			for(int i = 0; i < n; ++i)
			{
				if( !que_flags[i])
				{
					que_flags[i] = true;
					que[i] = customer;
					return;
				}
			}

		}

		void update( int time_now )
		{
			for(int i = 0; i < n; ++i)
			{
			}
		}

		void update_final( int time_final )
		{
		}
};

Bank *bank;

int main()
{
	int n, k, t;
	int hour, minute, second;

	int t_min = 8 * 60 * 60;
	int t_max = 17 * 60 * 60;

	scanf("%d%d", &n, &k);
	bank = new Bank();

	for(int i = 0; i < n; ++i)
	{
		scanf("%s %d", buff, &t);
		sscanf(buff, "%d:%d:%d", &hour, &minute, &second);
		customers[i].first = second + minute * 60 + hour * 360;
		customers[i].second = t * 60;
	}

	int cus_p = 0;
	sort( customers, customers + n );

	for(int i = t_min; i <= t_max; ++i)
	{
		while( bank->enable() && cus_p < n)
		{
			bank->push( customers[ cus_p++] );
		}

		bank->update( i );
	}
	bank->update_final( t_max );
	delete bank;
	return 0;
}
