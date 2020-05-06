/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-02-15 14:44:18
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

const int INF = 0x3f3f3f3f;
const int maxN = 105;

int E[maxN][maxN];
int arrDis[maxN];
bool arrVis[maxN];

int n, ans;

int ScanInt() {
	int len, tmp = 0;
	char str[10];
	scanf("%s", str);
	if (str[0] == 'x')
		return INF;
	len = strlen(str);
	for (int i = 0; i < len; i++)
		tmp = tmp * 10 + (str[i] - '0');
	return tmp;
}

void Dijkstra(int x) {
	int v, minN;
	memset(arrVis, 0, sizeof(arrVis));
	arrVis[x] = true;
	for (int i = 1; i <= n; i++)
		arrDis[i] = i == x ? 0 : E[x][i];
	for (int i = 1; i < n; i++) {
		minN = INF;
		v = -1;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[j] < minN) {
				minN = arrDis[j];
				v = j;
			}
		if (v == -1)
			break;
		arrVis[v] = true;
		for (int j = 1; j <= n; j++)
			if (arrVis[j] == false && arrDis[j] > arrDis[v] + E[v][j])
				arrDis[j] = arrDis[v] + E[v][j];
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (~scanf("%d", &n)) {
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				E[i][j] = i == j ? 0 : E[j][i] = ScanInt();
		Dijkstra(1);
		for (int i = 1; i <= n; i++)
			ans = max(ans, arrDis[i]);
		printf("%d\n", ans );
	}
	return 0;
}