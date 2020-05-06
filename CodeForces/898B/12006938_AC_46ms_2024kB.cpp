/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-18 15:47:16
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

int main(void) {
	int i, a, b, n;
	double y;
	cin >> n >> a >> b;
	for (i = 0; i <= n; i++) {
		y = (n - i * a ) / (double)b;
		if (y == (int)y && y >= 0) {
			cout << "YES" << endl;
			printf("%d %d\n", i, (int)y );
			return 0;
		} else if (i * a > n)
			break;
	}
	cout << "NO" << endl;
	return 0;
}