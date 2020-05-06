/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-24 16:12:32
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

int t, r, c;
int arr[maxN][maxN];

int DP(void) {
	int ret = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			arr[i][j] = max(arr[i - 1][j] + arr[i][j], arr[i][j - 1] + arr[i][j]);
	for (int i = 1; i <= c; i++)
		ret = max(ret, arr[r][i]);
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int kase = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &r, &c);
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				scanf("%d", &arr[i][j]);
		printf("Scenario #%d:\n", ++kase);
		printf("%d\n\n", DP());
	}
	return 0;
}