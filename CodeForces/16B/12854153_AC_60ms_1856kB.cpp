/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-05 13:26:14
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

struct arr
{
	int a;
	int b;
} s[20];

bool cmp(arr a, arr b) {
	return a.b > b.b;
}

int main(void) {
	int i, n, m;
	long long int ans = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d %d", &s[i].a, &s[i].b);
	sort(s, s + m, cmp);
	for (i = 0; i < m; i++) {
		if (n >= s[i].a) {
			ans += s[i].a * s[i].b;
			n -= s[i].a;
		} else {
			ans += n * s[i].b;
			n = 0;
		}
		if (n == 0)
			break;
	}
	printf("%lld\n", ans );
	return 0;
}