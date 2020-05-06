/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-20 17:34:57
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

long long int a[50], b[50];
long long int ans[2500];

int main(void) {
	int i, j, n, m, ptr = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (i = 0; i < m; i++)
		scanf("%lld", &b[i]);
	for (i = 0; i < n; i++) {
		ans[ptr] = a[i] * b[0];
		for (j = 1; j < m; j++)
			ans[ptr] = max(ans[ptr], a[i] * b[j]);
		ptr++;
	}
	sort(ans, ans + ptr);
	printf("%lld\n", ans[ptr - 2]);
	return 0;
}