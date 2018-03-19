#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e3 + 5;
const int DayH = 24;

int bill[DayH];
//char s1[MAXM], s2[MAXM], s3[MAXM];

class Node
{
	public:
		string name, date, stat;
		bool operator < (const Node &k)
		{
			if(this->name != k.name)
				return this->name < k.name;
			if(this->date != k.date)
				return this->date < k.date;
			return ( this-> stat == "on-line");
		}
};

class Node_ans
{
	public:
		string name, mouth;
//		vector< time >
};

void output( Node s[] , int len)
{
	for(int i = 0; i < len; ++i)
	{
		cout << s[i].name << ' ' << s[i].date << ' ' << s[i].stat << endl;
	}
}

Node lib[MAXN];

int main()
{
	Node node;
	int n, m;
	for(int i = 0; i < DayH; ++i)
		scanf("%d", bill + i);

	scanf("%d", &m);
	for(int i = 0; i < m; ++i)
		cin >> lib[i].name >> lib[i].date >> lib[i].stat;

	sort( lib, lib + m);
//	output( lib, m);

	for(int i = 0; i < m; ++i)
	{
	}

	return 0;
}
