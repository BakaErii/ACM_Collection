/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-03 18:17:28
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

int n, m;
int dparr[2][12885];
int w[3405], d[3405];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &d[i]);
	//DP
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m ; j++) {
			dparr[0][j] = dparr[1][j];
			if (w[i] <= j)
				dparr[1][j] = max(dparr[0][j - w[i]] + d[i], dparr[0][j]);
			else
				dparr[1][j] = dparr[0][j];
		}
	printf("%d\n", dparr[1][m] );
	return 0;
}