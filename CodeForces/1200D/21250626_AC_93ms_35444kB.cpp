/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-12 15:35:50
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

typedef long long int LL;

char G[maxN][maxN];
LL ansG[maxN][maxN];

int n, k;
int fR[maxN], fC[maxN], lR[maxN], lC[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", G[i] + 1);
		for (int j = 1; j <= n; j++)
			if (G[i][j] == 'B') {
				lR[i] = j;
				lC[j] = i;
				fR[i] = fR[i] == 0 ? j : fR[i];
				fC[j] = fC[j] == 0 ? i : fC[j];
			}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		if (fR[i] == 0)
			ans++;
		if (fC[i] == 0)
			ans++;
	}
	for (int i = 1; i <= n; i++) {
		LL tmpAns = 0;
		for (int j = 1; j <= n; j++) {
			if (i >= lC[j] && i - k + 1 <= fC[j] && fC[j] != 0)
				tmpAns++;
			if (j > k && i >= lC[j - k] && i - k + 1 <= fC[j - k] && fC[j - k] != 0)
				tmpAns--;
			ansG[i][j] += tmpAns;
		}
	}
	for (int j = 1; j <= n; j++) {
		LL tmpAns = 0;
		for (int i = 1; i <= n; i++) {
			if (j >= lR[i] && j - k + 1 <= fR[i] && fR[i] != 0)
				tmpAns++;
			if (i > k && j >= lR[i - k] && j - k + 1 <= fR[i - k] && fR[i - k] != 0)
				tmpAns--;
			ansG[i][j] += tmpAns;
		}
	}
	LL maxAns = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			maxAns = max(maxAns, ansG[i][j]);
	printf("%lld\n", maxAns + ans );
	return 0;
}