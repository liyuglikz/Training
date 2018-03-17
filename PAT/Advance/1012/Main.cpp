#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
const double eps = 1e-8;
const char str_sub[] = "ACME";
const int MAXN = 1e5 + 5;

class Grade
{
	public:
		int A;
		int C, M, E;
		int rank[4];
		bool operator < (const Grade &k)
		{
			if( this->A != k.A)
				return this->A < k.A;
			else if( this-> C != k.C)
				return this->C < k.C;
			else if( this->M != k.M)
				return this->M < k.M;
			return this->E < k.E;
		}

		void get_max_rank()
		{
			int ans = 0;
			for(int i = 1; i < 4; ++i)
			{
				if( rank[ans] > rank[i])
					ans = i;
			}
			printf("%d %c\n", rank[ans], str_sub[ans]);
		}
};

typedef pair<string, Grade> Node;

std::map<string, Grade> mps;
Node lib[MAXN];

bool cmp_A( Node &a, Node &b)
{	return a.second.A > b.second.A;}

bool cmp_C( Node &a, Node &b)
{	return a.second.C > b.second.C;}

bool cmp_M( Node &a, Node &b)
{	return a.second.M > b.second.M;}

bool cmp_E( Node &a, Node &b)
{	return a.second.E > b.second.E;}

int main()
{
	string str;
	Node node;
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; ++i)
	{
		cin >> node.first;
		scanf("%d%d%d", &node.second.C, &node.second.M, &node.second.E);
		node.second.A = (node.second.C + node.second.M + node.second.E) / 3.0;

		lib[i] = node;
	}

	// 特例: 1 1 3 4 
	int k = 0;//去重复
	sort( lib, lib + n, cmp_A);
	for(int i = 0; i < n; ++i)
	{
		if( i > 0 && lib[i].second.A == lib[i - 1].second.A)
			++k;//排名重复
		else
			k = 0;//排名重复后的排名如果不重复，则应该按原顺序继续排名（大坑点）
		lib[i].second.rank[0] = i + 1 - k;//去除重复的排名
	}

	k = 0;
	sort( lib, lib + n, cmp_C);
	for(int i = 0; i < n; ++i)
	{
		if( i > 0 && lib[i].second.C == lib[i - 1].second.C)
			++k;
		else
			k = 0;
		lib[i].second.rank[1] = i + 1 - k;
	}

	k = 0;
	sort( lib, lib + n, cmp_M);
	for(int i = 0; i < n; ++i)
	{
		if( i > 0 && lib[i].second.M == lib[i - 1].second.M)
			++k;
		else
			k = 0;
		lib[i].second.rank[2] = i + 1 - k;
	}

	k = 0;
	sort( lib, lib + n, cmp_E);
	for(int i = 0; i < n; ++i)
	{
		if( i > 0 && lib[i].second.E == lib[i - 1].second.E)
			++k;
		else
			k = 0;
		lib[i].second.rank[3] = i + 1 - k;
	}

	for(int i = 0; i < n; ++i)
	{
		mps.insert( lib[i] );
			/*//debug output
		cout << lib[i].first << ' ' << lib[i].second.A << ' ' << lib[i].second.C
			<< ' ' << lib[i].second.M << ' ' << lib[i].second.E << ": ";
		for(int j = 0; j < 4; ++j)
			printf("%d ", lib[i].second.rank[j]);
		puts("");
		*/
	}

	while( m-- )
	{
		cin >> str;
		if( mps.find( str ) == mps.end() )
			puts("N/A");
		else
			mps[str].get_max_rank();
	}

	return 0;
}
