/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-02 15:38:07
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

typedef long long int LL;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL x, y;
	scanf("%lld %lld", &x, &y);
	if (y == 0) {
		printf("No\n");
		return 0;
	}
	if (y == 1) {
		if (x == 0)
			printf("Yes\n");
		else
			printf("No\n");
		return 0;
	}
	if (x >= y - 1 && (x - y + 1) % 2 == 0)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}