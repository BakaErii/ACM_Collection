/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-27 13:20:55
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
	int q;
	LL a, b, c, ans;
	scanf("%d", &q);
	while (q--) {
		scanf("%lld %lld %lld", &a, &b, &c);
		ans = a + b + c;
		printf("%lld\n", ans / 2 );
	}
	return 0;
}