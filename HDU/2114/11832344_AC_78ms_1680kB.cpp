/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-03 20:01:04
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
	__int64 ans, n;
	while (~scanf("%I64d", &n)) {
		n %= 10000;
		ans = (((n + 1) * n / 2) * ((n + 1) * n / 2)) % 10000;
		printf("%04I64d\n", ans );
	}
	return 0;
}
