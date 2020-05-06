/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-05 00:17:15
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

typedef long long int LL;

int n, m;
char arr[maxN][maxN];
int arrCnt[maxN][5];
int arrScore[maxN];

LL ans = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &arrScore[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arrCnt[j][arr[i][j] - 'A']++;
	for (int i = 0; i < m; i++) {
		int mx = 0;
		int idx = 0;
		for (int j = 0; j < 5; j++) {
			if (mx < arrCnt[i][j]) {
				idx = j;
				mx = arrCnt[i][j];
			}
		}
		ans += (LL)arrCnt[i][idx] * (LL)arrScore[i];
	}
	printf("%lld\n", ans );
	return 0;
}