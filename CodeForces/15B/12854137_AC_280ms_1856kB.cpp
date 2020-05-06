/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-01 23:53:16
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

long long int fuckAbs(long long int a) {
	return a >= 0 ? a : -a;
}

int main(void) {
	long long int t, n, m, ans, dx, dy, sx, sy, x1, y1, x2, y2;
	cin >> t;
	while (t--) {
		//init
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		ans = n * m;
		dx = n - max(x1, x2) + min(x1, x2);
		dy = m - max(y1, y2) + min(y1, y2);
		ans -= dx * dy * 2;
		sx = sy = 0;
		if (dx > fuckAbs(x1 - x2))
			sx = dx - fuckAbs(x1 - x2);
		if (dy > fuckAbs(y1 - y2))
			sy = dy - fuckAbs(y1 - y2);
		ans += sx * sy;
		cout << ans << endl;
	}
	return 0;
}