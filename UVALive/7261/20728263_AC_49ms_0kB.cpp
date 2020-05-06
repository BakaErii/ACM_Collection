/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-24 15:20:56
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

int T, r, n;
LL arrHeight[maxN];
LL totArea;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, t, w, h;
	scanf("%d", &T);
	while (T--) {
		memset(arrHeight, 0, sizeof(arrHeight));
		totArea = 0;
		scanf("%d", &r);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d %d", &l, &t, &w, &h);
			arrHeight[l] += h;
			arrHeight[l + w] -= h;
			totArea += (LL)w * (LL)h;
		}
		for (int i = 1; i <= r; i++)
			arrHeight[i] = arrHeight[i - 1] + arrHeight[i];
		LL nowArea = 0;
		int ans = 0;
		for (ans = 0; 2 * nowArea < totArea; ans++) {
			nowArea += arrHeight[ans];
		}
		while (arrHeight[ans] == 0 && ans < r)
			ans++;
		printf("%d\n", ans );
	}
	return 0;
}