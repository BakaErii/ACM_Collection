/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-20 16:27:39
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

int arr[100000];

int main(void) {
	int i, n, pos, dx = 1e+9;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (dx > abs((arr[i] - 1) - (1000000 - arr[i]))) {
			dx = abs((arr[i] - 1) - (1000000 - arr[i]));
			pos = i;
		}
	}
	printf("%d\n", min(arr[pos] - 1, 1000000 - arr[pos]));
	return 0;
}