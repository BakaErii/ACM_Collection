/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-28 16:05:35
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

char arr[50][51];

int main(void) {
	int minx, miny, maxx, maxy;
	int i, j, n, m;
	cin >> n >> m;
	getchar();
	minx = miny = maxx = maxy = -1;
	for (i = 0; i < n; i++)
		cin.getline(arr[i], 51);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (arr[i][j] == '*') {
				if (minx == -1)
					minx = i;
				if (miny == -1)
					miny = j;
				if (maxx == -1)
					maxx = i;
				if (maxy == -1)
					maxy = j;
				minx = min(minx, i);
				miny = min(miny, j);
				maxx = max(maxx, i);
				maxy = max(maxy, j);
			}
		}
	for (i = minx; i <= maxx; i++) {
		for (j = miny; j <= maxy; j++)
			putchar(arr[i][j]);
		putchar('\n');
	}
	return 0;
}