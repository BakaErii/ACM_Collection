/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-23 17:55:30
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
	int w1, h1, w2, h2;
	int ans = 0;
	scanf("%d %d %d %d", &w1, &h1, &w2, &h2);
	ans += (h1 + h2 + 2) * 2;
	ans += w1;
	ans += w2;
	int mx = abs(w2 - w1);
	if (mx >= 1)
		ans += mx;
	printf("%d\n", ans );
	return 0;
}