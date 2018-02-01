#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> msg;
typedef pair<int, msg> student;
map< int, msg> mps;

int main()
{
	int k, n;
	string name, id;
	cin >> n;
	while(n--)
	{
		cin >> name >> id >> k;
		mps.insert( student( k, msg( name, id) ) );
	}

	cout << mps.rbegin()->second.first << ' ' << mps.rbegin()->second.second << endl;
	cout << mps.begin()->second.first << ' ' << mps.begin()->second.second << endl;
	return 0;
}
