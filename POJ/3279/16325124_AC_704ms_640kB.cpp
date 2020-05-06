/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-08 07:55:51
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

const int maxN = 20;
const int INF = 0x3f3f3f3f;
const int dx[] = {1, 0, 0, -1, 0};
const int dy[] = {0, 1, 0, 0, -1};

int n, m, minAns = INF;
int arrRaw[maxN][maxN];
int arrTmp[maxN][maxN];
int arrAns[maxN][maxN];

bool isNeedFlip(int x, int y) {
	int nowColor = arrRaw[x][y];
	for (int i = 0; i < 5; i++) {
		int nowX = x + dx[i];
		int nowY = y + dy[i];
		if (nowX >= 0 && nowX < m && nowY >= 0 && nowY < n)
			nowColor += arrTmp[nowX][nowY];
	}
	return nowColor % 2;
}

int DFS(void) {
	for (int i = 1; i < m; i++)
		for (int j = 0; j < n; j++)
			if (isNeedFlip(i - 1, j))
				arrTmp[i][j] = 1;
	for (int i = 0; i < n; i++)
		if (isNeedFlip(m - 1, i))
			return -1;
	int ret = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (arrTmp[i][j] == 1)
				ret++;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arrRaw[i][j]);
	for (int i = 0; i < (1 << n); i++) {
		//INIT
		memset(arrTmp, 0, sizeof(arrTmp));
		for (int j = 0; j < n; j++)
			arrTmp[0][n - j - 1] = (i >> j) & 1;
		int opNum = DFS();
		if (opNum < minAns && opNum > 0) {
			minAns = opNum;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					arrAns[i][j] = arrTmp[i][j];
		}
	}
	if (minAns == INF)
		printf("IMPOSSIBLE\n");
	else
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				printf("%d%c", arrAns[i][j], j == n - 1 ? '\n' : ' ' );
	return 0;
}