#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
const double esp = 1e-12;


const int maxn = int(1e6+50);
const double dis_ss = sqrt(2.0);
const double dis_tt = 1.0;



struct _point{
	double x, y;
	_point(){};
	_point(double _x, double _y){ x = _x; y = _y; }
	_point operator - (const _point &a) const{
		_point tt;
		tt.x = x - a.x;
		tt.y = x - a.y;
		return tt;
	}
	_point operator +(const _point &a) const{
		_point tt;
		tt.x = x + a.x;
		tt.y = y + a.y;
	}
	_point operator *(const int &k)const{
		_point tt;
		tt.x = x*k;
		tt.y = x*y;
		return tt;
	}
}pp[maxn];


_point youdu;

bool cmp_0(_point a, _point b){
	return (a.x - youdu.x)*(b.y - youdu.y) - (a.y - youdu.y)*(b.x - youdu.x) > 0;
}

bool cmp_1(_point a, _point b){
	return (a.x - youdu.x)*(b.y - youdu.y) - (a.y - youdu.y)*(b.x - youdu.x) > 0;
}

bool cmp_2(_point a, _point b){
	return (a.x - youdu.x)*(b.y - youdu.y) - (a.y - youdu.y)*(b.x - youdu.x) > 0;
}

bool cmp_3(_point a, _point b){
	return (a.x - youdu.x)*(b.y - youdu.y) - (a.y - youdu.y)*(b.x - youdu.x) > 0;
}


bool cmp(_point a, _point b){
	return (a.x - youdu.x)*(b.y - youdu.y) - (a.y - youdu.y)*(b.x - youdu.x) > 0;
}



double cross(_point a, _point b, _point c){
	return (b - a).x*(c - b).y - (b - a).y*(c - b).y;
}

set<pair<double, double> > s;

int main(){
	int n;
	while (cin >> n){
		s.clear();
		double left = 1e7+50, right = 0-(1e7+50), up = 0-(1e7+50), down = (1e7+50);
		double x, y;
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &x, &y);
			if (x > right) right = x;
			if (x < left) left = x;
			if (y > up) up = y;
			if (y < down) down = y;
			s.insert(pair<double, double>(x, y));
		}
		int kkk = 0;
		set<pair<double, double> >::iterator it;
		for (it = s.begin(); it != s.end(); it++, kkk++){
			pp[kkk].x = it->first;
			pp[kkk].y = it->second;
		}
		n = kkk;
		youdu.x = -int(1e6 + 50); youdu.y = -int(1e6 + 50);
		sort(pp, pp + n,cmp_0);	
		int flag = 0;
		double dis = 0;
		_point _v_tmp(pp[0].x, pp[0].y - 1);
		_point start = _v_tmp;
		_point _tt;
		for (int i = 0; flag < 4; i++, i %= n){
			if (flag == 0 && (pp[i].x > _v_tmp.x || pp[i].x == right)){
				if (pp[i].x == right){ _tt.x = pp[i].x + 1; _tt.y = pp[i].y; flag++; youdu = _tt; }
				else { _tt.x = pp[i].x; _tt.y = pp[i].y - 1; }
				double _x_y = abs(abs(_tt.x - _v_tmp.x) - abs(_tt.y - _v_tmp.y));
				dis += _x_y*dis_tt + (max(abs(_tt.x - _v_tmp.x), abs(_tt.y - _v_tmp.y))-_x_y) * dis_ss;
				_v_tmp = _tt;
				if (flag == 1){
					sort(pp, pp + n, cmp_1);
					i = -1;
				}
			}
			else if (flag == 1 && (pp[i].y > _v_tmp.y || pp[i].y == up)){
				if (pp[i].y == up){ _tt.x = pp[i].x; _tt.y = pp[i].y + 1; flag++; youdu = _tt; }
				else { _tt.x = pp[i].x + 1; _tt.y = pp[i].y; }
				double _x_y = abs(abs(_tt.x - _v_tmp.x) - abs(_tt.y - _v_tmp.y));
				dis += _x_y*dis_tt + (max(abs(_tt.x - _v_tmp.x), abs(_tt.y - _v_tmp.y)) - _x_y) * dis_ss;
				_v_tmp = _tt;
				if (flag == 2){
					sort(pp, pp + n, cmp_2);
					i = -1;
				}
			}
			else if (flag == 2 && (pp[i].x < _v_tmp.x || pp[i].x == left)){
				if (pp[i].x == left){ _tt.x = pp[i].x - 1; _tt.y = pp[i].y; flag++; youdu = _tt; }
				else { _tt.x = pp[i].x; _tt.y = pp[i].y + 1; }
				double _x_y = abs(abs(_tt.x - _v_tmp.x) - abs(_tt.y - _v_tmp.y));
				dis += _x_y*dis_tt + (max(abs(_tt.x - _v_tmp.x), abs(_tt.y - _v_tmp.y)) - _x_y) * dis_ss;
				_v_tmp = _tt;
				if (flag == 3){
					sort(pp, pp + n, cmp_3);
					i = -1;
				}
			}
			else if (flag == 3 && (pp[i].y < _v_tmp.y || pp[i].y == down)){
				if (pp[i].y == down){ _tt.y = pp[i].y - 1; _tt.x = pp[i].x; flag++; youdu = _tt; }
				else { _tt.x = pp[i].x - 1; _tt.y = pp[i].y; }
				double _x_y = abs(abs(_tt.x - _v_tmp.x) - abs(_tt.y - _v_tmp.y));
				dis += _x_y*dis_tt + (max(abs(_tt.x - _v_tmp.x), abs(_tt.y - _v_tmp.y)) - _x_y) * dis_ss;
				_v_tmp = _tt;
				if (_tt.x != start.x || _tt.y!=start.y){
					dis += abs(_tt.x - start.x) + abs(_tt.y - start.y);
				}
			}
		}
		printf("%.6f\n", dis+esp);
	}
	return 0;
}




/*
5
0 1 1 1 2 1 3 1 4 1
5
1 1 1 2 1 3 1 4 1 5
7
0 0 10 0 0 10 10 10
5 5 6 6 7 7
8
1 2 2 3 4 5 6 1 4 8 6 9 4 3 3 4

9
0 0
0 3 3 0 0 -3 -3 0
1 -1 -1 1 1 1 -1 -1


0 0
0 3 3 0 0 -3 -3 0


5
0 0 1 0 -1 0 0 1 0 -1
2
0 0 0 0

*/


/*
4
-1000000 -1000000
-1000000 1000000
1000000 -1000000
1000000 1000000




*/





/*
13.6568

13.6568

45.6568

28.7279

*/
