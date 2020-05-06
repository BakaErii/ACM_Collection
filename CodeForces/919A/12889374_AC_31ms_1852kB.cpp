/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-31 21:04:59
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
	double ans;
	int i, n, m, a, b, mina, minb;
	//init
	ans = 0;
	cin >> n >> m;
	cin >> mina >> minb;
	for (i = 1; i < n; i++) {
		cin >> a >> b;
		if ((double)a / b < (double)mina / minb) {
			mina = a;
			minb = b;
		}
	}
	ans = (double)m * mina / minb;
	printf("%.8lf\n", ans );
	return 0;
}