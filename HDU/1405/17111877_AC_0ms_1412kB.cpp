/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-21 14:01:23
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
	int n, cnt, kase = 0;
	bool isFirstOutput = true;
	while (~scanf("%d", &n) && n > 0) {
		if (!isFirstOutput)
			putchar('\n');
		isFirstOutput = false;
		printf("Case %d.\n", ++kase );
		cnt = 0;
		if (n % 2 == 0) {
			while (n % 2 == 0) {
				cnt++;
				n /= 2;
			}
			printf("2 %d ", cnt);
		}
		for (int i = 3; i <= n; i += 2) {
			cnt = 0;
			if (n % i == 0) {
				printf("%d ", i);
				while (n % i == 0) {
					cnt++;
					n /= i;
				}
				printf("%d ", cnt);
			}
		}
		putchar('\n');
	}
	return 0;
}