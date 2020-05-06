/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-27 14:25:05
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

const int INF = 100000;

int bTop, bButtom, bLeft, bRight;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q, n, x, y, bT, bB, bL, bR;
	scanf("%d", &q);
	while (q--) {
		// Init
		bTop = bRight = INF;
		bButtom = bLeft = -INF;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d %d %d", &x, &y, &bL, &bT, &bR, &bB);
			if (bL == 0)
				bLeft = max(x, bLeft);
			if (bT == 0)
				bTop = min(y, bTop);
			if (bR == 0)
				bRight = min(x, bRight);
			if (bB == 0)
				bButtom = max(y, bButtom);
		}
		if (bButtom <= bTop && bLeft <= bRight)
			printf("1 %d %d\n", bLeft, bTop );
		else
			printf("0\n");
	}
	return 0;
}