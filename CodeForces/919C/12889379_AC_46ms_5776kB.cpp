/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-31 21:34:54
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

char arr[2000][2001];
int dp[2001];

int ans, n, m, k;

int main(void) {
	int i, j, tmp;
	cin >> n >> m >> k;
	ans = 0;
	getchar();
	for (i = 0; i < n; i++)
		gets(arr[i]);
	memset(dp, 0, sizeof(dp));
	for (i = 0; i < n; i++) {
		tmp = 0;
		for (j = 0; j < m; j++)
			if (arr[i][j] == '.') {
				if (k == 1) {
					ans++;
				} else {
					tmp++;
					if (tmp >= k)
						ans++;
					dp[j]++;
					if (dp[j] >= k)
						ans++;
				}
			} else {
				tmp = 0;
				dp[j] = 0;
			}
	}
	cout << ans << endl;
	return 0;
}