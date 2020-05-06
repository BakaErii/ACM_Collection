/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-18 23:24:09
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

int prime[10001];

int main(void) {
	int i, j, ans, tot, n, pn;
	pn = 0;
	for (i = 2; i < 10001; i++) {
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (j == i)
			prime[pn++] = i;
	}
	while (~scanf("%d", &n) && n != 0) {
		ans = 0;
		for (i = 0; i < pn; i++) {
			tot = 0;
			for (j = i; j < pn && tot < n; j++) {
				tot += prime[j];
				if (tot == n)
					ans++;
			}
		}
		printf("%d\n", ans );
	}
	return 0;
}