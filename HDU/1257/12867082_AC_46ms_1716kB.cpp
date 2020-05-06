/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-23 13:10:41
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

int dp[30001], arr[30001];

int main(void) {
	int ans, n, i, j;
	while (cin >> n) {
		ans = 1;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
			dp[i] = 1;
			for (j = 0; j < i; j++)
				if (arr[j] < arr[i])
					dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
	return 0;
}