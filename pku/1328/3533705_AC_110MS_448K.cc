#include <iostream>

#include <algorithm>

#include <cmath>

using namespace std;



const int size = 1100;

int N, d;

class Point 

{

	public:

	double l, r;

	bool init(int x, int y)

	{

		double v;

		if (y > d)

		{

			l = x;

			r = x;

			return 0;

		}

		else

		{

			v = sqrt(d * d - y * y);

			l = x - v;

			r = x + v;

			return 1;

		}

	}

} p[size];



double Min(double x, double y)

{

	return x < y ? x : y;

}



double Max(double x, double y)

{

	return x > y ? x : y;

}



bool cmp(const Point &a, const Point &b)

{

	return a.l < b.l;

}



void Solve(int t)

{

	bool ok;

	int i, x, y, cnt;

	double left, right;

	ok = 1;

	for (i = 0; i < N; i++)

	{

		cin>>x>>y;

		ok = ok && p[i].init(x, y);

	}

	cout<<"Case "<<t<<": ";

	if (!ok)

	{

		cout<<"-1\n";

		return;

	}

	sort(p, p + N, cmp);

	cnt = 1;

	left = p[0].l;

	right = p[0].r;

	for (i = 1; i < N; i++)

	{

		if (p[i].l > right)

		{

			cnt++;

			left = p[i].l;

			right = p[i].r;

		}

		else

		{

			left = p[i].l;

			right = Min(right, p[i].r);

		}

	}

	cout<<cnt<<endl;

}



int main()

{

	int t = 0;

	while (cin>>N>>d && (N + d))

	{

		Solve(++t);

	}

	return 0;

}


