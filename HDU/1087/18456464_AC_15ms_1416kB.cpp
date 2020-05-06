/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-28 21:38:39
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

const int maxN = 1005;

int arr[maxN];
int arrDp[maxN];

int n, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n) && n != 0) {
		// Init
		ans = 0;
		arrDp[0] = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < n; i++) {
			arrDp[i] = arr[i];
			for (int j = 0; j < i; j++)
				if (arr[i] > arr[j]) {
					arrDp[i] = max(arrDp[i], arr[i] + arrDp[j]);
				}
			ans = max(ans, arrDp[i]);
		}
		printf("%d\n", ans );
	}
	return 0;
}