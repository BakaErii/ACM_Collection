/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-23 19:06:35
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

#define LL long long int

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL a, b, c, d, ans;
	int t, longer;
	scanf("%d", &t);
	t--;
	scanf("%lld %lld", &a, &b);
	ans = min(a, b) + 1;
	while (t--) {
		scanf("%lld %lld", &c, &d);
		if (a >= b)
			longer = 0;
		else
			longer = 1;
		if (longer == 0 && d >= a && d != b) {
			if (a != b)
				ans++;
			ans += min(c - a, d - a);
		} else if (longer == 1 && c >= b && c != a) {
			if (a != b)
				ans++;
			ans += min(c - b, d - b);
		}
		a = c;
		b = d;
	}
	printf("%lld\n", ans);
	return 0;
}