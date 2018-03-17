#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

class Node
{
	public:
		string s1, s2, s3;
		bool operator < ( const Node &k )
		{
			return this->s2 < k.s2;
		}
};

bool cmp( Node &A, Node &B)
{
	return A.s3 > B.s3;
}

Node lib[MAXN];

int main()
{
	int n;
	string ans1, ans2;

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		cin >> lib[i].s1 >> lib[i].s2 >> lib[i].s3;

	sort( lib, lib + n);
	ans1 = lib->s1;
	sort( lib, lib + n, cmp);
	ans2 = lib->s1;
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
