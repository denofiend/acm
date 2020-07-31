//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>

using namespace std;


template <class T> void out(T x, int n){	for(int i = 0; i < n; ++i)	cout << x[i] << ' ';	cout << endl;	}
template <class T> void out(T x, int n, int m){	for(int i = 0; i < n; ++i)	out(x[i], m);	cout << endl;	}


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)	for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)	FOR(i, 0, b)
#define FORD(i, a, b)	for(int i = (int)a; i >= (int)b; --i)

int a[31], b[31];

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


bool inMaze(const int &x, const int &y){
	return 0 <= x && x < 5 && 0 <= y && y < 6;
}

int main(){
	int t, cas = 1, x, y, x0, y0;
	scanf("%d\n", &t);
	while (t--)
	{
		REP (i, 30)
		{
			scanf("%d", &a[i]);
		}

		REP (i, 30)
		{
			b[i] = (1<<i);
			x = i / 6;
			y = i % 6;
			REP (j, 4)
			{
				x0 = x + dir[j][0];
				y0 = y + dir[j][1];
				if (inMaze(x0, y0))
				{
					b[i] |= (1<<(x0*6+y0));
				}
			}
		}

		REP (i, 30)
		{
			FOR (j, i, 30)
			{
				if ((1<<i) & b[j])
				{
					swap(b[j], b[i]);
					swap(a[j], a[i]);
					break;
				}
			}
			
			FOR (j, i+1, 30)
			{
				if ((1<<i) & b[j])
				{
					b[j] ^= b[i];
					a[j] ^= a[i];
				}
			}
		}

		FORD (i, 29, 0)
		{
			REP (j, i)
			{
				if ((1<<i) & b[j])
				{
					a[j] ^= a[i];
				}
			}
		}
		printf("PUZZLE #%d\n", cas++);
		REP (i, 30)
		{
			printf("%d", a[i]);
			if (5 == i % 6)	printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
