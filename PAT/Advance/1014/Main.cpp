#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 21;
typedef pair<int, int> Node;
inline string getTime( int k )
{
	int h = k / 60;
	int min = k % 60;
	char s[10];
	sprintf( s, "%02d:%02d", h, min);
	return string(s);
}

int lib[MAXN];
int ans_t[MAXN];

class Bank
{
	public:
		int que_n, que_max;
		queue<Node> que[MAXM];
		int t_last[MAXN];

	explicit Bank( int a = 0, int b = 0)
	{
		que_n = a;
		que_max = b;
		for(int i = 0; i < que_n; ++i)
			t_last[i] = 480;
	}

	bool enable()
	{
		for(int i = 0; i < que_n; ++i)
		{
			if( que[i].size() < que_max)
				return true;
		}
		return false;
	}

	void push( int k, int k_t )
	{
		int que_min = 0;
		// find shortest queue
		for(int i = 1; i < que_n; ++i)
		{
			if( que[i].size() < que[ que_min ].size())
				que_min = i;
		}

		if( que[que_min].size() < que_max)
		{
//			cout << que_min << ' ' << que[que_min].size() << "-> " << k << ": "<< getTime( k_t + t_last[que_min]) << endl;
			que[que_min].push( Node(k, t_last[ que_min ]) );
			t_last[ que_min ] += k_t;
		}
	}

	void update( int time_now )
	{
		for(int i = 0; i < que_n; ++i)
		{
			while( (!que[i].empty()) && que[i].front().second + lib[ que[i].front().first] <= time_now )
			{
				//printf("pop: %d %d %d\n", que[i].front().first, que[i].front().second, time_now);
				ans_t[ que[i].front().first ] = que[i].front().second + lib[que[i].front().first];
				que[i].pop();
			}
		}
	}

			/*
			   无须判断 ans_t[val] > t_max 注意题意
			 "those customers who cannot be served before 17:00, you must output "Sorry" instead"
			 只要在17:00之前接受服务，17:00之后完成都没关系
			*/

	void update_final( int time_final)
	{
		for(int i = 0; i < que_n; ++i)
		{
			if( (!que[i].empty()) && que[i].front().second  < time_final )
			{
				//printf("pop: %d %d %d\n", que[i].front().first, que[i].front().second, time_now);
				ans_t[ que[i].front().first ] = que[i].front().second + lib[que[i].front().first];
				que[i].pop();
			}
		}
	}

};

Bank *bank;//bank class

int main()
{
	int n, m, k, q;
	int t_min = 8 * 60;
	int t_max = 17 * 60;
	int w_que = 0;
	int cus = 1;
	memset( ans_t, -1, sizeof( ans_t) );

	scanf("%d%d%d%d", &n, &m, &k, &q);
	bank = new Bank(n, m);	//create a bank

	for(int i = 1; i <= k; ++i)
		scanf("%d", lib + i);

	for( int t = t_min; t <= t_max; ++t)
	{
//		printf("%d:--------------------\n", t);
		while( bank->enable() && cus <= k )//push customs as we can
		{
			bank->push( cus, lib[cus] );
//			cout << cus << ' ' << getTime( t + lib[cus]) << endl;
			++cus;
		}
		bank->update( t ); //update window's status
	}

	bank->update_final( t_max );//找出所有能在17:00之前接受服务，但是在17:00之后完成的顾客

	int val;
	while( q-- )
	{
		scanf("%d", &val);

		if( ans_t[val] == -1)
			puts("Sorry");
		else
			cout << getTime( ans_t[val])<<endl;
	}
	delete bank; //destroy bank
	return 0;
}
