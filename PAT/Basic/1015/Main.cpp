#include <bits/stdc++.h>

using namespace std;
int N, L, H;

class Student
{
	public:
		Student( int a = 0, int b = 0, int c = 0) : id(a), score_d(b), score_c(c)
		{
			if( score_d >= H && score_c >= H)
				t = 0;
			else if( score_d >= H)
				t = 1;
			else if( score_d < H && score_c < H && score_d >= score_c )
				t = 2;
			else
				t = 3;
			score = score_d + score_c;
		}
		void output()
		{
			printf("%08d %d %d\n", id, score_d, score_c);
		}
		int id, score_d, score_c, score;
		int t;
};
vector<Student> vec;

bool cmp( Student &a, Student &b)
{
	if( a.t == b.t)
	{
		if( a.score != b.score)
			return a.score > b.score;
		else if( a.score_d != b.score_d)
			return a.score_d > b.score_d;
		else
			return a.id < b.id;
	}
	return a.t < b.t;
}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &N, &L, &H);

	for(int i = 0; i < N; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		if( b >= L && c >= L)
			vec.push_back( Student( a, b, c) );
	}
	sort( vec.begin(), vec.end(), cmp);
	printf("%lu\n", vec.size());
	vector<Student> :: iterator it;
	for( it = vec.begin(); it != vec.end(); ++it)
		it->output();

	return 0;
}
