#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int n, k, last = 0, ans = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &k);
		ans += (5 + (k > last? (k - last) * 6 : (last - k) * 4));
		last = k;
	}
	cout << ans << endl;
	return 0;
}
