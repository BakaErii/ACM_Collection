/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-15 16:50:55
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

long long int n, k, s, l;
long long int curr = 1;

long long int step(long long int x) {
	if (curr - x > 0)
		return curr - x;
	return curr + x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%lld %lld %lld", &n, &k, &s);
	if (k > s || k * (n - 1) < s) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	while (k > 0) {
		l = min(n - 1, s - (k - 1));
		curr = step(l);
		printf("%lld ", curr );
		s -= l;
		k--;
	}
	putchar('\n');
	return 0;
}