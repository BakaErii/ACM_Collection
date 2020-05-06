/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-27 16:23:55
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
	int i, n, vol, cap, cap1 = 0, cap2 = 0;
	long long int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &vol);
		sum += vol;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &cap);
		if (cap > cap1) {
			cap2 = cap1;
			cap1 = cap;
		} else if (cap > cap2) {
			cap2 = cap;
		}
	}
	if (sum <= cap1 + cap2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}