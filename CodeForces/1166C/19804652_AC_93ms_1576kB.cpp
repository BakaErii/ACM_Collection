/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-19 10:27:29
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

const int maxN = 200005;

typedef long long int LL;

int n, ptr;
LL arr[maxN];
LL ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		arr[ptr++] = abs(tmp);
	}
	sort(arr, arr + ptr);
	for (int i = 0; i < ptr; i++) {
		int cnt = upper_bound(arr, arr + ptr, abs(arr[i]) * 2) - arr;
		// printf("%d\n", cnt - i - 1);
		ans += cnt - i - 1;
	}
	printf("%lld\n", ans );
	return 0;
}
