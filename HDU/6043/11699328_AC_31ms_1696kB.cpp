/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-24 19:23:15
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
	unsigned long long  n, k, tmp, num;
	num = 0;
	while (cin >> n >> k) {
		if (k <= n) {
			printf("Case #%llu: %llu\n", ++num, k );
		} else {
			tmp = (k - n) % (n - 1);
			if (tmp != 0)
				printf("Case #%llu: %llu\n", ++num, tmp );
			else if (((k - n ) / (n - 1)) % 2 == 0)
				printf("Case #%llu: %llu\n", ++num, n );
			else
				printf("Case #%llu: %llu\n", ++num, n - 1 );
		}
	}
	return 0;
}