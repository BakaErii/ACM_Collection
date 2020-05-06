/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-05 11:59:57
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, t, a, b, ansLeft, ansRight, tmp;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		//init
		ansLeft = 0;
		ansRight = 0;
		scanf("%d %d", &a, &b);
		while (!(a == 1 && b == 1)) {
			tmp = 0;
			if (a > b) {
				tmp = (a - 1) / b;
				ansLeft += tmp;
				a -= tmp * b;
			} else {
				tmp = (b - 1) / a;
				ansRight += tmp;
				b -= tmp * a;
			}
		}
		printf("Scenario #%d:\n", i );
		printf("%d %d\n", ansLeft, ansRight );
		putchar('\n');
	}
	return 0;
}