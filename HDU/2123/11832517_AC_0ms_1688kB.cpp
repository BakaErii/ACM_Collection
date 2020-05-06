/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-03 21:06:22
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
	int i, j, n, t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; i++){
			for (j = 1; j <= n; j++) {
				if (j != 1)
					printf(" ");
				printf("%d", i * j);
			}
			printf("\n");
		}
	}
	return 0;
}