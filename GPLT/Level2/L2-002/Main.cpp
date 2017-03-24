#include <bits/stdc++.h>

using namespace std;
const int MAXM = 6;
const int MAXN = 1e5 + 5;

class node
{
	public:
		explicit node(){}
		int add;
		int next;
		int val;
};

char add_s[MAXM];
int n;
node lib[MAXN];
node buff0[MAXN];
node buff1[MAXN];

map<int, node> mps;
set<int> val_s;

void deal( node s[], int len)
{
	for(int i = 0; i < len - 1; ++i)
	{
		s[i].next = s[i + 1].add;
	}
	s[len - 1].next = -1;
}
void output( node &now )
{
//	cout << now.add << " " << now.val << " " << now.next << endl;
	printf("%05d %d ", now.add, now.val);
	if( now.next != -1)
		printf("%05d\n", now.next);
	else
		puts("-1");
}

void solve()
{
	scanf("%s%d", add_s, &n);
	int st;
	sscanf(add_s, "%d", &st);

	for(int i = 0; i < n; ++i)
	{
//		cin >> lib[i].add >> lib[i].val >> lib[i].next;
		scanf("%d%d%d", &lib[i].add, &lib[i].val, &lib[i].next);
		mps.insert( pair<int, node> (lib[i].add, lib[i]));
	}

	int len = 0;
	for(int i = st; i != -1; i = mps[i].next)
	{
		lib[len++] = mps[i];
//		cout << lib[len - 1].add << " " << lib[len - 1].val << " " << lib[len - 1].next << endl;
	}

	int l0 = 0, l1 = 0;
	for( int i = 0; i < len; ++i)
	{
		if( val_s.end() == val_s.find( abs(lib[i].val )))
		{
			val_s.insert( abs(lib[i].val ));
			buff0[ l0++ ] = lib[i];
		}
		else
		{
			buff1[ l1++ ] = lib[i];
		}
	}

	deal( buff0, l0 );
	deal( buff1, l1 );

	for(int i = 0; i < l0; ++i)
		output( buff0[i] );
	for(int i = 0; i < l1; ++i)
		output( buff1[i] );
}

int main()
{
	solve();
	return 0;
}
