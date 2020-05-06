/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-21 14:49:51
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
	int t, n, ans, sum, doubleSum;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = (int)sqrt(n);
		doubleSum = (int)sqrt(n / 2.0);
		ans = sum + doubleSum;
		ans %= 2;
		printf("%d\n", ans );
	}
	return 0;
}