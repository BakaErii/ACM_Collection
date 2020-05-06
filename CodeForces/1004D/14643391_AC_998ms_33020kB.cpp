/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-18 13:32:24
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

int arr[maxN];
int cnt[maxN];
map<int, int> mp;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, tmp, t, border = 0;
	int n, m, x, y;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
		mp[tmp]++;
	}
	for (auto it : mp)
		border = max(border, it.first);
	for (i = 1; i < maxN; i++)
		if (arr[i] != i << 2) {
			x = i;
			break;
		}
	for (n = 1; n <= t; n++)
		if (t % n == 0) {
			m = t / n;
			y = n + m - x - border;
			if (abs(n - x) + abs(m - y) != border)
				continue;
			for (i = 0; i <= m + n; i++)
				cnt[i] = 0;
			for (i = 1; i <= n; i++)
				for (j = 1; j <= m; j++)
					cnt[abs(x - i) + abs(y - j)]++;
			bool isAns = true;
			for (i = 0; i <= m + n; i++)
				if (cnt[i] != arr[i]) {
					isAns = false;
					break;
				}
			if (isAns) {
				cout << n << ' ' << m << endl;
				cout << x << ' ' << y << endl;
				return 0;
			}
		}
	printf("-1\n");
	return 0;
}