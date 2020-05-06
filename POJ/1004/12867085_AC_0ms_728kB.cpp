/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-18 22:47:51
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
	float tmp, ans;
	while (~scanf("%f", &tmp)) {
		ans = 0;
		ans += tmp;
		for (int i = 0; i < 11; i++) {
			scanf("%f", &tmp);
			ans += tmp;
		}
		ans /= 12;
		printf("$%.2f\n", ans );
	}
	return 0;
}