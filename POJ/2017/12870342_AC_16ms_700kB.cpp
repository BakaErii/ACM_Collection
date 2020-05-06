/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-19 02:30:26
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
	int n, ans, speed, mile, mileafter;
	while (~scanf("%d", &n) && n != -1) {
		ans = 0;
		mileafter = -1;
		while (n--) {
			scanf("%d %d", &speed, &mile);
			if (mileafter == -1) {
				ans += mile * speed;
			} else {
				ans += (mile - mileafter) * speed;
			}
			mileafter = mile;
		}
		printf("%d miles\n",ans );
	}
	return 0;
}