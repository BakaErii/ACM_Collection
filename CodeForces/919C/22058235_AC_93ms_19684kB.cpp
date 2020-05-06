/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-10-04 16:39:55
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

const int maxN = 2005;

int n, m, k;
int ans;
char arr[maxN][maxN];
int arrDp[maxN][maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%s", arr[i] + 1);
	if(k == 1) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(arr[i][j] == '.')
					ans++;
		printf("%d\n", ans );
		return 0;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(arr[i][j] == '*') {
				if(arrDp[i][j - 1] >= k)
					ans += arrDp[i][j - 1] - k + 1;
				arrDp[i][j] = 0;
			} else
				arrDp[i][j] = arrDp[i][j - 1] + 1;
	for(int i = 1; i <= n; i++)
		if(arrDp[i][m] >= k)
			ans += arrDp[i][m] - k + 1;
	memset(arrDp, 0, sizeof(arrDp));
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if(arr[j][i] == '*') {
				if(arrDp[j - 1][i] >= k) {
					ans += arrDp[j - 1][i] - k + 1;
				}
				arrDp[j][i] = 0;
			} else
				arrDp[j][i] = arrDp[j - 1][i] + 1;
	for(int i = 1; i <= m; i++)
		if(arrDp[n][i] >= k)
			ans += arrDp[n][i] - k + 1;
	printf("%d\n", ans );
	return 0;
}