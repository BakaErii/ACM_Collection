/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-27 13:57:30
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

const int maxN = 200005;

int arrIdx[maxN];
int pointCnt;
int n, k;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q, tmp, loc;
	scanf("%d", &q);
	while (q--) {
		// Init
		pointCnt = 0;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			if (tmp % 2 == 1)
				arrIdx[++pointCnt] = i;
		}
		// Judge
		if (pointCnt < k)
			printf("NO\n");
		else if ((pointCnt - k) % 2 == 0) {
			printf("YES\n");
			loc = 1;
			while (pointCnt - loc + 1 > k)
				loc += 2;
			arrIdx[pointCnt] = n;
			for (int i = loc; i <= pointCnt; i++) {
				if (i != loc)
					putchar(' ');
				printf("%d", arrIdx[i]);
			}
			putchar('\n');
		} else
			printf("NO\n");
	}
	return 0;
}