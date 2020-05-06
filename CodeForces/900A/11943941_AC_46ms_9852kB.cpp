/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-11 23:59:01
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

struct point {
	int x;
	int y;
} p[1000000];

bool cmp(point a, point b) {
	return a.x < b.x;
}

int main(void) {
	int i, n;
	int znum, fnum;
	cin >> n;
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p, p + n, cmp);
	znum = 0;
	fnum = 0;
	for (i = 1; i < n; i++)
		if (p[i].x > 0)
			znum++;
		else
			fnum++;
	if (min(znum, fnum) == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	znum = 0;
	fnum = 0;
	for (i = 0; i < n - 1; i++)
		if (p[i].x > 0)
			znum++;
		else
			fnum++;
	if (min(znum, fnum) == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}