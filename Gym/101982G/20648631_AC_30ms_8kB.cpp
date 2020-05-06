/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-22 13:09:56
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const double EPS = 1e-6;
const double PI = 3.14159265;
const double INF = 1e100;

struct Point
{
	double x, y;
};

struct LineSeg
{
	Point s, e;
};


double dist(Point p1, Point p2)
{
	return ( sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) ) );
}

double dotmultiply(Point p1, Point p2, Point p0)
{
	return ((p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y));
}

double relation(Point p, LineSeg l)
{
	LineSeg tl;
	tl.s = l.s;
	tl.e = p;
	return dotmultiply(tl.e, l.e, l.s) / (dist(l.s, l.e) * dist(l.s, l.e));
}

Point perpendicular(Point p, LineSeg l)
{
	double r = relation(p, l);
	Point tp;
	tp.x = l.s.x + r * (l.e.x - l.s.x);
	tp.y = l.s.y + r * (l.e.y - l.s.y);
	return tp;
}

double ptolinesegdist(Point p, LineSeg l, Point &np)
{
	double r = relation(p, l);
	if (r < 0)
	{
		np = l.s;
		return dist(p, l.s);
	}
	if (r > 1)
	{
		np = l.e;
		return dist(p, l.e);
	}
	np = perpendicular(p, l);
	return dist(p, np);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double ans = INF;
	double x, y, x1, y1, x2, y2;
	scanf("%lf %lf %lf %lf %lf %lf", &x, &y, &x1, &y1, &x2, &y2);
	Point tmp;
	Point a;
	a.x = x;
	a.y = y;
	ans = min(ans, ptolinesegdist(a, {{x1, y1}, {x1, y2}}, tmp));
	ans = min(ans, ptolinesegdist(a, {{x1, y1}, {x2, y1}}, tmp));
	ans = min(ans, ptolinesegdist(a, {{x1, y2}, {x2, y2}}, tmp));
	ans = min(ans, ptolinesegdist(a, {{x2, y1}, {x2, y2}}, tmp));
	printf("%.3lf\n", ans );
	return 0;
}