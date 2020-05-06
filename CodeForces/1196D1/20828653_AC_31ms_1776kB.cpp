/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-27 14:54:03
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
const int INF = 0x3f3f3f3f;
const char strRGB[] = "RGB";

char str[maxN];
int arrCost[maxN];
int arrSum[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q, n, k, ans;
	scanf("%d", &q);
	while (q--) {
		ans = INF;
		scanf("%d %d", &n, &k);
		scanf("%s", str);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++)
				arrCost[j + 1] = str[j] == strRGB[(j + i) % 3] ? 0 : 1;
			arrSum[0] = 0;
			for (int j = 1; j <= n; j++)
				arrSum[j] = arrCost[j] + arrSum[j - 1];
			for (int j = k; j <= n; j++)
				ans = min(ans, arrSum[j] - arrSum[j - k]);
		}
		printf("%d\n", ans );
	}
	return 0;
}