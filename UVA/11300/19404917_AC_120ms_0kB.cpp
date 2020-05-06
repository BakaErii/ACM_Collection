/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-04-22 22:49:02
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

const int maxN = 1000005;

typedef long long int LL;

int n;
LL arr[maxN];
LL totNum, lastNum, midNum;
LL ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n)) {
		// INIT
		ans = 0;
		totNum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &arr[i]);
			totNum += arr[i];
		}
		lastNum = totNum / n;
		arr[0] = 0;
		for (int i = 1; i < n; i++)
			arr[i] = arr[i - 1] + arr[i] - lastNum;
		sort(arr, arr + n);
		midNum = arr[n / 2];
		for (int i = 0; i < n; i++)
			ans += abs(midNum - arr[i]);
		printf("%lld\n", ans );
	}
	return 0;
}