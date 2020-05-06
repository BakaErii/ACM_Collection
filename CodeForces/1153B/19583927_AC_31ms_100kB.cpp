/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-04 12:12:14
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

const int maxN = 105;

int n, m, h;

int arrF[maxN];
int arrL[maxN];
int arrH[maxN][maxN];
int arrAns[maxN][maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++)
		scanf("%d", &arrF[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &arrL[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arrH[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arrH[i][j] == 1)
				arrAns[i][j] = min(arrL[i], arrF[j]);
			printf("%d ", arrAns[i][j]);
		}
		putchar('\n');
	}
	return 0;
}