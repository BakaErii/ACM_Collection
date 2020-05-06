/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-02 14:48:38
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

const int maxN = 305;

struct Point
{
	double x, y;
} P[maxN];

double Multiply(Point a, Point b, Point c) {
	double a1, b1, a2, b2;
	a1 = b.x - a.x, a2 = c.x - b.x;
	b1 = b.y - a.y, b2 = c.y - b.y;
	return a1 * b2 - a2 * b1;
}

int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &P[i].x, &P[i].y);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			double mxA = 0, mxB = 0;
			for (int k = 0; k < n; k++) {
				double tmp = Multiply(P[i], P[j], P[k]);
				if (tmp > 0)
					mxA = max(mxA, tmp / 2);
				else
					mxB = max(mxB, -tmp / 2);
			}
			if (mxA > 0 && mxB > 0)
				ans = max(ans, mxA + mxB);
		}
	printf("%.10f\n", ans );
	return 0;
}