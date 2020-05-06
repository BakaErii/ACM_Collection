/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-23 20:14:43
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

int n, m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(~scanf("%d %d", &n, &m)) {
		double ans = 0;
		for(int i = 1; i < n; i++) {
			double dis = i / (double)n * (n + m);
			ans += fabs(dis - floor(dis + 0.5)) / (n + m);
		}
		printf("%.4f\n", ans * 10000);
	}
	return 0;
}