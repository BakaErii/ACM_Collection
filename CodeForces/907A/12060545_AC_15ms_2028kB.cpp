/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-23 22:00:23
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
	int v1, v2, v3, vm;
	cin >> v1 >> v2 >> v3 >> vm;
	if (!(v3 * 2 >= vm)) {
		printf("-1\n");
		return 0;
	} else  if (vm >= v2) {
		printf("-1\n");
		return 0;
	} else  if (v3 > vm * 2) {
		printf("-1\n");
		return 0;
	} else {
		if (vm >= v3)
			printf("%d\n%d\n%d\n", v1 * 2, v2 * 2, vm);
		else
			printf("%d\n%d\n%d\n", v1 * 2, v2 * 2, v3);
	}
	return 0;
}