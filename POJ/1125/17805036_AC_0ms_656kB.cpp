/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-18 23:23:17
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
const int INF = 0x3f3f3f3f;

int t, n;
int arr[maxN][maxN];

void init(int x) {
	for (int i = 0; i <= x; i++)
		for (int j = 0; j <= x; j++)
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
	return;
}

int Dji(int start) {
	int maxVal = 0;
	int minVal, minPos;
	int arrDis[maxN];
	bool arrVis[maxN];
	for (int i = 1; i <= t; i++) {
		arrDis[i] = arr[start][i];
		arrVis[i] = false;
	}
	arrVis[start] = true;
	// Dji
	for (int i = 1; i < t; i++) {
		minVal = INF;
		for (int j = 1; j <= t; j++)
			if (arrVis[j] == false && arrDis[j] < minVal) {
				minPos = j;
				minVal = arrDis[j];
			}
		if (minVal == INF)
			return INF;
		arrVis[minPos] = true;
		for (int j = 1; j <= t; j++)
			if (arr[minPos][j] != INF)
				if (arrDis[minPos] + arr[minPos][j] < arrDis[j])
					arrDis[j] = arrDis[minPos] + arr[minPos][j];
	}
	maxVal = 0;
	for (int i = 1; i <= t; i++)
		maxVal = max(maxVal, arrDis[i]);
	return maxVal;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int u, val;
	int minVal, start, tmpVal;
	while (~scanf("%d", &t) && t != 0) {
		// INIT
		init(t);
		minVal = INF;
		for (int i = 1; i <= t; i++) {
			scanf("%d", &n);
			for (int j = 0; j < n; j++) {
				scanf("%d %d", &u, &val);
				arr[i][u] = val;
			}
		}
		// Solve
		for (int j = 1; j <= t; j++) {
			tmpVal = Dji(j);
			if (tmpVal < minVal) {
				start = j;
				minVal = tmpVal;
			}
		}
		if (minVal == INF)
			printf("disjoint\n");
		else
			printf("%d %d\n", start, minVal );
	}
	return 0;
}